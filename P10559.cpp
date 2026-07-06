#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// --- 极限优化配置 ---
// 1. 数组开够大
const int N = 300005;
const int M = 3000005; 

// 2. 只需要云朵数和答案开 long long，其他用 int 甚至 short (如果存的下) 节省带宽
long long a[N], ans[N]; 
int n, m, q;
int deg[N]; 
bool vis[N]; 

// --- 手写快读 (针对大量输入) ---
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

// --- 链式前向星 1：原图 (无向，边数要乘2) ---
// 不使用 vector<int> g[N]
int h1[N], nxt1[M * 2], to1[M * 2], tot1;
inline void add_orig(int u, int v) {
    to1[++tot1] = v;
    nxt1[tot1] = h1[u];
    h1[u] = tot1;
}

// --- 链式前向星 2：DAG (定向图，单向，边数 M 即可) ---
// 存的是“小弟指向大哥”的边
int h2[N], nxt2[M], to2[M], tot2;
inline void add_dag(int u, int v) {
    to2[++tot2] = v;
    nxt2[tot2] = h2[u];
    h2[u] = tot2;
}

// --- 手写队列 (比 std::queue 快) ---
int que[N], q_head, q_tail;

void solve() {
    // 使用快读
    n = read(); m = read(); q = read();

    // 读入边
    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        add_orig(u, v);
        add_orig(v, u);
        deg[u]++;
        deg[v]++;
    }

    // --- 拓扑排序 (剥洋葱) ---
    q_head = 0; q_tail = 0;
    
    // 初始入队
    for (int i = 1; i <= n; i++) {
        if (deg[i] <= 10) {
            que[q_tail++] = i;
        }
    }

    while (q_head < q_tail) {
        int u = que[q_head++];
        
        // 标记已删除
        if (vis[u]) continue; 
        vis[u] = true;

        // 遍历原图邻居
        for (int i = h1[u]; i; i = nxt1[i]) {
            int v = to1[i];
            
            if (vis[v]) continue; // 邻居如果已经不在图里了，跳过

            // u 是当前剥离的，v 是剩下的，所以 u -> v
            add_dag(u, v); 

            deg[v]--;
            // 只有当度数降到阈值时才入队，避免重复
            if (deg[v] == 10) {
                que[q_tail++] = v;
            }
        }
    }

    // 读入初始云朵数
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        // 初始化缓存：把自己的值加给大哥
        for (int j = h2[i]; j; j = nxt2[j]) {
            int big = to2[j];
            ans[big] += a[i];
        }
    }

    // 处理查询
    while (q--) {
        int op = read();
        if (op == 1) {
            int x = read();
            int v = read();
            a[x] += v;
            // 更新大哥的缓存
            for (int i = h2[x]; i; i = nxt2[i]) {
                ans[to2[i]] += v;
            }
        } else {
            int x = read();
            long long res = ans[x]; // 小弟们的贡献
            // 加上大哥们的当前值
            for (int i = h2[x]; i; i = nxt2[i]) {
                res += a[to2[i]];
            }
            printf("%lld\n", res); // printf 比 cout 快
        }
    }
}

int main() {
    solve();
    return 0;
}