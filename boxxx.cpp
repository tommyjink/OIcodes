#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 终态地图（仅用作参考，%是出生点，&是目标点，$在(1,4)）
    vector<string> final_map = {
        ".##.##.",
        "#..#$.#",
        "#.....#",
        "#.$...#",
        ".#.&.#.",
        "..#.#..",
        "...#..."
    };

    // 62 步神级走位
    string actions = "DSDWAASSDSDWDSDSDWDWWSAASAAWDDWAASDAWDWWASSDDSSAAWDSDWWSAAAASD";

    // 生成干净的物理碰撞地图（剥离动态元素）
    vector<string> clean_map = final_map;
    for (int r = 0; r < 7; ++r) {
        for (int c = 0; c < 7; ++c) {
            if (clean_map[r][c] == '%' || clean_map[r][c] == '$' || clean_map[r][c] == '&') {
                clean_map[r][c] = '.';
            }
        }
    }

    int valid_count = 0;

    // 只有 1 个箱子，遍历所有可能的 7x7 格子
    for (int br = 0; br < 7; ++br) {
        for (int bc = 0; bc < 7; ++bc) {
            // 必须是空地
            if (clean_map[br][bc] != '.') continue;
            // 箱子不能出生在玩家起点 % (1,1)
            if (br == 1 && bc == 1) continue;
            // 箱子不能出生在目标点 & (4,3)
            if (br == 4 && bc == 3) continue;

            // 玩家初始必定在 % (1,1)
            int pr = 1, pc = 1;
            // 当前假设的箱子初始位置
            int curr_br = br, curr_bc = bc;

            // 严格执行 62 步推箱子物理引擎
            for (char a : actions) {
                int dr = 0, dc = 0;
                if (a == 'W') dr = -1;
                else if (a == 'S') dr = 1;
                else if (a == 'A') dc = -1;
                else if (a == 'D') dc = 1;

                int npr = pr + dr, npc = pc + dc;

                // 玩家撞墙
                if (clean_map[npr][npc] == '#') continue;

                // 玩家遇到箱子
                if (npr == curr_br && npc == curr_bc) {
                    int nbr = curr_br + dr, nbc = curr_bc + dc;
                    // 箱子撞墙（推不动，玩家也无法移动）
                    if (clean_map[nbr][nbc] == '#') continue;
                    
                    // 推动成功
                    curr_br = nbr; curr_bc = nbc;
                    pr = npr; pc = npc;
                } else {
                    // 玩家走空地
                    pr = npr; pc = npc;
                }
            }

            // 校验结局：经过这 62 步后，这个箱子有没有刚好停在终态的 (1,4) 位置？
            // （不再限制玩家的终点位置！）
            if (curr_br == 1 && curr_bc == 4) {
                valid_count++;
                
                cout << "    // 方案 " << valid_count << endl;
                cout << "    string map_candidate_" << valid_count << "[7] = {" << endl;
                for (int r = 0; r < 7; ++r) {
                    cout << "        \"";
                    for (int c = 0; c < 7; ++c) {
                        if (r == 1 && c == 1) cout << "%"; // 标回出生点
                        else if (r == br && c == bc) cout << "$"; // 标上箱子初始位置
                        else if (r == 4 && c == 3) cout << "&"; // 标回目标点
                        else cout << clean_map[r][c];
                    }
                    cout << "\"";
                    if (r < 6) cout << ",";
                    cout << endl;
                }
                cout << "    };" << endl << endl;
            }
        }
    }

    cout << "穷举完毕！总共找到 " << valid_count << " 种完全合法的初始状态！" << endl;
    return 0;
}