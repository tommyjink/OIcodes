#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, k, a[50005], dp[3005][3005], ls[3005][3005], siz[50005];
vector<int> e[50005];
void dfs(int u, int fa) {
    dp[u][0] = 0;
    siz[u] = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int i = 0; i <= siz[u]; i++) {
            for (int j = 0; j <= siz[v]; j++) {
                ls[u][i + j] = max(ls[u][i + j], dp[u][i] + dp[v][j]);
            }
        }
        siz[u] += siz[v];
        for (int i = 0; i <= siz[u]; i++) dp[u][i] = ls[u][i], ls[u][i] = -0x3f3f3f3f3f3f;
    }
    siz[u]++;
    for (int i = siz[u]; i >= 1; i--) dp[u][i] = dp[u][i - 1] + a[u];
//    cout << u << "\n";
//    for (int i = 0; i <= siz[u]; i++) cout << dp[u][i] << " ";
//    cout << "\n";
    dp[u][0] = 0;
    return ;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    memset(dp, -0x3f, sizeof dp);
    memset(ls, -0x3f, sizeof ls);
    dfs(1, 0);
    cout << dp[1][k] << "\n";
    return ;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    T = 1;
    while (T--) solve();
    return 0;
}
/*
7 4
5 -2 4 6 3 -5 8
1 2
1 3
2 4
2 5
3 6
3 7
*/