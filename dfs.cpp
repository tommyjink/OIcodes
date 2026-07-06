#include <vector>
using namespace std;

// 假设 re 是 int 类型的宏定义（例如 #define re register）
#define re register

vector<vector<int>> G; // 图的邻接表表示
vector<bool> vis;      // 访问标记数组
int cnt[2];            // cnt[0]记录访问的节点数，cnt[1]记录总边数

bool dfs(int u) {
    bool tag = false;
    vis[u] = true;
    ++cnt[0];
    cnt[1] += G[u].size();

    for (re int v : G[u]) {
        if (u == v) {
            tag = true; // 存在自环
        }
        if (!vis[v]) {
            tag |= dfs(v);
        }
    }

    return tag;
}