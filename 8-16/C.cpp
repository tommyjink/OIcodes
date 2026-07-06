#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int n, k, p;
int ans;
vector<int> adj[1005];
bool vis[1005];

int popcount(int x) {
    int res = 0;
    while (x) { res += x & 1; x >>= 1; }
    return res;
}

void dfs(int pos, int last) {
    if (pos == p) { ans = (ans + 1) % MOD; return; }
    for (int v : adj[last]) {
        if (!vis[v]) {
            vis[v] = 1;
            dfs(pos + 1, v);
            vis[v] = 0;
        }
    }
}

signed main() {
    cin >> n >> k >> p;
    if (p == 1) { cout << n % MOD << endl; return 0; }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && popcount(i ^ j) == k) {
                adj[i].push_back(j);
            }
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        dfs(1, i);
    }
    cout << ans % MOD << endl;
    return 0;
}