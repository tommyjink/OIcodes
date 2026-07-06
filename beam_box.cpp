#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

constexpr int t = 5;
char c[10][7][7];
uint64_t targets[10];
bool is_dead[10][7][7];
int dist_field[10][7][7];

struct JointState {
    uint64_t maps[t];
    bool operator==(const JointState& o) const {
        for (int i = 0; i < t; ++i) if (maps[i] != o.maps[i]) return false;
        return true;
    }
};

struct HashJointState {
    size_t operator()(const JointState& js) const {
        size_t h = 0;
        for (int i = 0; i < t; ++i) h ^= js.maps[i] + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        return h;
    }
};

// 带有启发式分数的状态
struct ScoredState {
    JointState state;
    int h_score;
    bool operator<(const ScoredState& o) const {
        return h_score < o.h_score; // 分数越低越接近终点
    }
};

struct ParentInfo {
    JointState parent;
    char move;
};

constexpr size_t NUM_SHARDS = 4096;
struct Shard {
    mutex mtx;
    unordered_map<JointState, ParentInfo, HashJointState> map;
} shards[NUM_SHARDS];

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};
char dir_char[] = {'W', 'A', 'S', 'D'};
inline int pos(int x, int y) { return x * 7 + y; }

void precompute_distances() {
    memset(dist_field, 0x3f, sizeof(dist_field));
    for (int i = 0; i < t; ++i) {
        queue<pair<int, int>> q;
        for (int r = 0; r < 7; ++r) {
            for (int c_idx = 0; c_idx < 7; ++c_idx) {
                if ((targets[i] >> pos(r, c_idx)) & 1) {
                    dist_field[i][r][c_idx] = 0; q.push({r, c_idx});
                }
            }
        }
        while (!q.empty()) {
            auto [r, c_idx] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nr = r + dx[d], nc = c_idx + dy[d];
                if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7 && c[i][nr][nc] != '#') {
                    if (dist_field[i][nr][nc] > dist_field[i][r][c_idx] + 1) {
                        dist_field[i][nr][nc] = dist_field[i][r][c_idx] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
}

int get_heuristic(const JointState& state) {
    int h = 0;
    for (int i = 0; i < t; ++i) {
        uint64_t boxes = state.maps[i] & 0x1FFFFFFFFFFFFULL;
        for (int p = 0; p < 49; ++p) {
            if ((boxes >> p) & 1) h += dist_field[i][p / 7][p % 7];
        }
    }
    return h;
}

string traceback(JointState end_state, JointState start_state) {
    string path = "";
    JointState curr = end_state;
    while (!(curr == start_state)) {
        size_t h = HashJointState()(curr);
        ParentInfo info = shards[h % NUM_SHARDS].map[curr];
        path += info.move;
        curr = info.parent;
    }
    reverse(path.begin(), path.end());
    return path;
}

string solveParallelBeam() {
    JointState start_state; memset(&start_state, 0, sizeof(start_state));
    for (int i = 0; i < t; ++i) {
        targets[i] = 0; uint64_t start_boxes = 0; int px = 0, py = 0;
        for (int x = 0; x < 7; ++x) {
            for (int y = 0; y < 7; ++y) {
                if (c[i][x][y] == '%') { px = x; py = y; c[i][x][y] = '.'; }
                else if (c[i][x][y] == '$') { start_boxes |= (1ULL << pos(x, y)); c[i][x][y] = '.'; }
                else if (c[i][x][y] == '&') { targets[i] |= (1ULL << pos(x, y)); c[i][x][y] = '.'; }
            }
        }
        start_state.maps[i] = start_boxes | ((uint64_t)py << 49) | ((uint64_t)px << 52);
    }

    precompute_distances();

    memset(is_dead, 0, sizeof(is_dead));
    for (int i = 0; i < t; ++i) {
        for (int r = 0; r < 7; ++r) {
            for (int c_idx = 0; c_idx < 7; ++c_idx) {
                if (c[i][r][c_idx] == '#') { is_dead[i][r][c_idx] = true; continue; }
                if (i == 0) { if (!(r == 5 && (c_idx >= 2 && c_idx <= 4))) is_dead[i][r][c_idx] = true; }
                else if (i == 1) { if (!(c_idx == 5 && (r >= 2 && r <= 4))) is_dead[i][r][c_idx] = true; }
                else if (i == 2) { if (!((r == 1 || r == 2) && (c_idx >= 2 && c_idx <= 4))) is_dead[i][r][c_idx] = true; }
                else if (i == 3) { if (!((r >= 1 && r <= 3) && (c_idx >= 2 && c_idx <= 4))) is_dead[i][r][c_idx] = true; }
                else if (i == 4) { if (!(r >= 2 && r <= 5 && c_idx >= 2 && c_idx <= 5)) is_dead[i][r][c_idx] = true; }
                if (!is_dead[i][r][c_idx] && !((targets[i] >> pos(r, c_idx)) & 1)) {
                    bool wall_u = (r == 0 || c[i][r-1][c_idx] == '#'); bool wall_d = (r == 6 || c[i][r+1][c_idx] == '#');
                    bool wall_l = (c_idx == 0 || c[i][r][c_idx-1] == '#'); bool wall_r = (c_idx == 6 || c[i][r][c_idx+1] == '#');
                    if ((wall_u && wall_l) || (wall_u && wall_r) || (wall_d && wall_l) || (wall_d && wall_r)) is_dead[i][r][c_idx] = true;
                }
            }
        }
    }

    int num_threads = thread::hardware_concurrency();
    cout << ">> 检测到核心数: " << num_threads << "，启动并行集束搜索(Parallel Beam Search)..." << endl;

    vector<ScoredState> current_level;
    current_level.push_back({start_state, get_heuristic(start_state)});
    shards[HashJointState()(start_state) % NUM_SHARDS].map[start_state] = {start_state, '\0'};

    atomic<bool> found_win(false);
    JointState win_state;
    int depth = 0;
    
    // 【集束宽度】每层最多保留 30 万个最优状态，砍掉其余分支，防止爆内存！
    constexpr size_t BEAM_WIDTH = 300000; 

    while (!current_level.empty() && !found_win) {
        depth++;
        
        // 如果当前层太大，按雷达分数排序并截断
        if (current_level.size() > BEAM_WIDTH) {
            sort(current_level.begin(), current_level.end());
            current_level.resize(BEAM_WIDTH);
        }
        
        int best_h = current_level.empty() ? -1 : current_level[0].h_score;
        cout << "第 " << depth << " 层 | 展开节点: " << current_level.size() << " | 最佳预估距离: " << best_h << endl;

        vector<vector<ScoredState>> next_level_chunks(num_threads);
        vector<thread> threads;
        int chunk_size = (current_level.size() + num_threads - 1) / num_threads;

        for (int t_id = 0; t_id < num_threads; ++t_id) {
            threads.emplace_back([&, t_id]() {
                int start_idx = t_id * chunk_size;
                int end_idx = min((int)current_level.size(), (t_id + 1) * chunk_size);
                vector<ScoredState>& local_next = next_level_chunks[t_id];
                local_next.reserve(chunk_size * 4);

                for (int idx = start_idx; idx < end_idx; ++idx) {
                    if (found_win) return;
                    const JointState& curr_state = current_level[idx].state;

                    for (int d = 0; d < 4; ++d) {
                        JointState next_state; bool doomed = false;
                        for (int i = 0; i < t; ++i) {
                            uint64_t s = curr_state.maps[i];
                            int px = (s >> 52) & 7; int py = (s >> 49) & 7; uint64_t boxes = s & 0x1FFFFFFFFFFFFULL; 
                            int nx = px + dx[d], ny = py + dy[d];
                            if (nx >= 0 && nx < 7 && ny >= 0 && ny < 7 && c[i][nx][ny] != '#') {
                                int npos = pos(nx, ny);
                                if ((boxes >> npos) & 1) { 
                                    int nnx = nx + dx[d], nny = ny + dy[d];
                                    if (nnx >= 0 && nnx < 7 && nny >= 0 && nny < 7 && c[i][nnx][nny] != '#') {
                                        int nnpos = pos(nnx, nny);
                                        if (!((boxes >> nnpos) & 1)) {
                                            if (is_dead[i][nnx][nny]) { doomed = true; break; }
                                            px = nx; py = ny; boxes ^= (1ULL << npos); boxes |= (1ULL << nnpos);
                                        }
                                    }
                                } else { px = nx; py = ny; }
                            }
                            next_state.maps[i] = boxes | ((uint64_t)py << 49) | ((uint64_t)px << 52);
                        }
                        if (doomed) continue;

                        size_t h = HashJointState()(next_state);
                        size_t shard_idx = h % NUM_SHARDS;
                        bool is_new = false;
                        {
                            lock_guard<mutex> lock(shards[shard_idx].mtx);
                            auto res = shards[shard_idx].map.try_emplace(next_state, ParentInfo{curr_state, dir_char[d]});
                            is_new = res.second;
                        }

                        if (is_new) {
                            bool win = true;
                            for (int i = 0; i < t; ++i) {
                                if ((next_state.maps[i] & 0x1FFFFFFFFFFFFULL) != targets[i]) { win = false; break; }
                            }
                            if (win) {
                                bool expected = false;
                                if (found_win.compare_exchange_strong(expected, true)) win_state = next_state;
                                return;
                            }
                            local_next.push_back({next_state, get_heuristic(next_state)});
                        }
                    }
                }
            });
        }

        for (auto& th : threads) th.join();
        if (found_win) break;

        current_level.clear();
        for (const auto& chunk : next_level_chunks) {
            current_level.insert(current_level.end(), chunk.begin(), chunk.end());
        }
    }

    if (found_win) return traceback(win_state, start_state);
    return "No Solution";
}

int main() {
    string map1[7] = { "###....", "#%#....", "#.#....", "#.#....", "#.#####", "#.$.&.#", "#######" };
    string map2[7] = { "###.###", "#%#.#.#", "#.#.#&#", "#.#.#.#", "#..##$#", "#.....#", "#######" };
    string map3[7] = { "#######", "#%&$..#", "#.&$..#", "#.###.#", "#.###.#", "#.....#", "#######" };
    string map4[7] = { "#######", "#%$.&.#", "#.$.&.#", "#.$.&.#", "#######", "......#", "#######" };
    string map5[7] = { "#######", "#%##..#", "#.##$&#", "#.##..#", "#.$...#", "#..&..#", "#######" };

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            c[0][i][j] = map1[i][j]; c[1][i][j] = map2[i][j]; c[2][i][j] = map3[i][j]; c[3][i][j] = map4[i][j]; c[4][i][j] = map5[i][j];
        }
    }

    string result = solveParallelBeam();
    if (result != "No Solution") {
        cout << "\n========== 集束破局路径 ==========\n";
        cout << result << "\n总步数: " << result.length() << " 步" << endl;
    } else {
        cout << "抱歉，由于集束宽度限制或地图原因，没有找到解。" << endl;
    }
    return 0;
}