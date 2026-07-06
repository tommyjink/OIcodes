#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <array>

using namespace std;

// 全局变量定义（按照你的要求，假设在外部会被赋值）
int t;
char c[10][7][7];
uint64_t targets[10]; // 记录每张图的目标点位置（状态压缩）

// 单张地图的状态结构体
struct MapState
{
    int px, py;
    uint64_t boxes; // 使用64位整数的位运算压缩箱子状态（7x7=49位）

    bool operator<(const MapState &o) const
    {
        if (px != o.px)
            return px < o.px;
        if (py != o.py)
            return py < o.py;
        return boxes < o.boxes;
    }

    bool operator==(const MapState &o) const
    {
        return px == o.px && py == o.py && boxes == o.boxes;
    }
};

// 所有地图的联合状态结构体
struct JointState
{
    array<MapState, 10> maps; // 使用 std::array 避免堆内存分配，提高速度

    bool operator<(const JointState &o) const
    {
        // 只比较前 t 个有效地图
        for (int i = 0; i < t; ++i)
        {
            if (maps[i] < o.maps[i])
                return true;
            if (o.maps[i] < maps[i])
                return false;
        }
        return false;
    }
};

// 移动方向：上(W), 左(A), 下(S), 右(D)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char dir_char[] = {'W', 'A', 'S', 'D'};

// 将二维坐标转化为一维索引 (0~48)
inline int pos(int x, int y)
{
    return x * 7 + y;
}

// 核心求解函数
string solveSokoban()
{
    JointState start_state;

    // 1. 解析初始地图状态
    for (int i = 0; i < t; ++i)
    {
        targets[i] = 0;
        start_state.maps[i].boxes = 0;
        for (int x = 0; x < 7; ++x)
        {
            for (int y = 0; y < 7; ++y)
            {
                if (c[i][x][y] == '%')
                {
                    start_state.maps[i].px = x;
                    start_state.maps[i].py = y;
                    c[i][x][y] = '.'; // 提取起始点后恢复为空地
                }
                else if (c[i][x][y] == '$')
                {
                    start_state.maps[i].boxes |= (1ULL << pos(x, y));
                    c[i][x][y] = '.'; // 提取箱子后恢复为空地
                }
                else if (c[i][x][y] == '&')
                {
                    targets[i] |= (1ULL << pos(x, y));
                    c[i][x][y] = '.'; // 提取目标点后恢复为空地
                }
                // 注意：由于我们将 %, $, & 都提取到了状态变量中，
                // 现在 c[10][7][7] 里面只剩下 '#' (墙壁) 和 '.' (空地)
            }
        }
    }

    // 检查是否所有图的箱子都已经推到目标点
    auto is_win = [&](const JointState &js)
    {
        for (int i = 0; i < t; ++i)
        {
            if (js.maps[i].boxes != targets[i])
                return false;
        }
        return true;
    };

    if (is_win(start_state))
        return ""; // 初始即胜利

    // 2. BFS 寻找最短共同路径
    set<JointState> visited; // 用于防止重复搜索
    queue<pair<JointState, string>> q;

    visited.insert(start_state);
    q.push({start_state, ""});

    while (!q.empty())
    {
        auto [curr_state, path] = q.front();
        q.pop();

        // 尝试四个方向的移动
        for (int d = 0; d < 4; ++d)
        {
            JointState next_state = curr_state;

            // 处理每张地图的独立移动逻辑
            for (int i = 0; i < t; ++i)
            {
                int nx = curr_state.maps[i].px + dx[d];
                int ny = curr_state.maps[i].py + dy[d];

                // 检查玩家移动是否越界或撞墙
                if (nx >= 0 && nx < 7 && ny >= 0 && ny < 7 && c[i][nx][ny] != '#')
                {
                    int npos = pos(nx, ny);

                    // 检查前方是否有箱子
                    if ((curr_state.maps[i].boxes >> npos) & 1)
                    {
                        int nnx = nx + dx[d];
                        int nny = ny + dy[d];
                        // 检查箱子是否能被推动：不能越界、不能撞墙、前方不能有另一个箱子
                        if (nnx >= 0 && nnx < 7 && nny >= 0 && nny < 7 && c[i][nnx][nny] != '#')
                        {
                            int nnpos = pos(nnx, nny);
                            if (!((curr_state.maps[i].boxes >> nnpos) & 1))
                            {
                                // 推动成功：更新玩家位置
                                next_state.maps[i].px = nx;
                                next_state.maps[i].py = ny;
                                // 更新箱子位置 (位运算 XOR 清除旧位，OR 设置新位)
                                next_state.maps[i].boxes ^= (1ULL << npos);
                                next_state.maps[i].boxes |= (1ULL << nnpos);
                            }
                        }
                        // 如果箱子推不动，玩家在这一张地图的本次移动失效（保持不变）
                    }
                    else
                    {
                        // 前方是空地或目标点，正常通行
                        next_state.maps[i].px = nx;
                        next_state.maps[i].py = ny;
                    }
                }
                // 撞墙处理：越界或撞墙时，该地图的 next_state 维持原本的 curr_state 不变
            }

            // 检查这一步走完后是否通关
            if (is_win(next_state))
            {
                return path + dir_char[d];
            }

            // 去重并加入队列继续搜索
            if (visited.find(next_state) == visited.end())
            {
                visited.insert(next_state);
                q.push({next_state, path + dir_char[d]});
            }
        }
    }
    return "No Solution"; // 无解返回
}
int main()
{
    t = 1; // 设置当前共有 2 张地图需要同步

    // 第一张地图：人和箱子在第 1 行（0-based）
    // 只需要向右走两步 (D, D) 即可把 $ 推到 & 上
   string map1[7] = {
    "#######",
    "#%##..#",
    "#.##$&#",
    "#.##..#",
    "#.$...#",
    "#..&..#",
    "#######"
};

    // 第二张地图：人和箱子在第 2 行
    // 同样也是向右走两步 (D, D) 即可过关
    // string map2[7] = {
    // 	"###.###",
    // 	"#%#.#.#",
    // 	"#.#.#&#",
    // 	"#.#.#.#",
    // 	"#..##$#",
    // 	"#.....#",
    // 	"#######"
    // };
    // string map3[7] = {
    // 	"#######",
    // 	"#%&$..#",
    // 	"#.&$..#",
    // 	"#.###.#",
    // 	"#.###.#",
    // 	"#.....#",
    // 	"#######"
    // };
    // string map4[7] = {
    // 	"#######",
    // 	"#%$.&.#",
    // 	"#.$.&.#",
    // 	"#.$.&.#",
    // 	"#######",
    // 	"......#",
    // 	"#######"
    // };
    // 将我们写好的字符串地图填入全局变量 c[10][7][7] 中
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            c[0][i][j] = map1[i][j];
            // c[1][i][j] = map2[i][j];
            // c[2][i][j] = map3[i][j];
            // c[3][i][j] = map4[i][j];
        }
    }

    cout << "已加载 " << t << " 张地图，开始同步推箱子求解..." << endl;

    // 调用之前写好的核心函数
    string result = solveSokoban();

    if (result == "No Solution")
    {
        cout << "抱歉，没有找到可以同步通关的路线。" << endl;
    }
    else if (result == "")
    {
        cout << "初始状态就已经全部通关了！" << endl;
    }
    else
    {
        cout << "找到通关路径！请按以下顺序移动: " << result << endl;
    }

    return 0;
}
