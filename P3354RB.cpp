#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int maxn = 105;

inline int read() {
    int d = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        d = d * 10 + ch - 48;
        ch = getchar();
    }
    return d;
}

int n, k;
int w[maxn], v[maxn], d[maxn];
int head[maxn], ver[maxn], nxt[maxn], tot;

inline void add(int u, int v) {
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}

int dep[maxn];
int f[maxn][maxn][maxn], g[maxn][maxn][maxn];
int stk[maxn], tots;

void dfs(int u) {
    stk[++tots] = u;
    for (int p = head[u]; p; p = nxt[p]) {
        int v = ver[p];
        dep[v] = dep[u] + d[v];
        dfs(v);
        for (int i = 1; i <= tots; ++i) {
            for (int j = k; j >= 0; --j) {
                f[u][stk[i]][j] += f[v][stk[i]][0];
                g[u][stk[i]][j] += f[v][u][0];
                for (int l = 1; l <= j; ++l) {
                    f[u][stk[i]][j] = min(f[u][stk[i]][j], f[v][stk[i]][l] + f[u][stk[i]][j - l]);
                    g[u][stk[i]][j] = min(g[u][stk[i]][j], f[v][u][l] + g[u][stk[i]][j - l]);
                }
            }
        }
    }
    for (int i = 1; i <= tots; ++i) {
        for (int j = k; j >= 1; --j)
            f[u][stk[i]][j] = min(f[u][stk[i]][j] + w[u] * (dep[u] - dep[stk[i]]), g[u][stk[i]][j - 1]);
        f[u][stk[i]][0] += w[u] * (dep[u] - dep[stk[i]]);
    }
    --tots;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read(), k = read();
    for (int i = 1; i <= n; ++i) {
        w[i] = read(), v[i] = read(), d[i] = read();
        add(v[i], i);
    }
    dfs(0);
    cout << f[0][0][k] << endl;
    return 0;
}