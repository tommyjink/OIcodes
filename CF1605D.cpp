#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, u, v, ans[200005];
vector<ll> E[200005], a, b, s1, s2;
bool vis[200005];

void dfs(ll x, ll w, ll fa) {
    if (w) a.push_back(x);
    else b.push_back(x);
    for (auto y : E[x]) {
        if (y == fa) continue;
        dfs(y, w ^ 1, x);
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear(); b.clear(); s1.clear(); s2.clear();
        for (ll i = 1; i <= n; i++) E[i].clear(), vis[i] = 0;
        for (ll i = 1; i < n; i++) {
            cin >> u >> v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(1, 0, 0);
        ll now = a.size(), t_val = 1;
        while (t_val * 2 <= n) t_val *= 2;
        if (now >= t_val) {
            for (ll i = t_val; i <= n; i++) s1.push_back(i), vis[i] = 1;
            now -= (n - t_val + 1);
        }
        for (ll i = 0; i <= 20; i++) {
            if (now & (1ll << i)) {
                for (ll j = (1ll << i); j < (1ll << (i + 1)); j++) s1.push_back(j), vis[j] = 1;
            }
        }
        for (ll i = 1; i <= n; i++) {
            if (!vis[i]) s2.push_back(i);
        }
        ll sz_a = a.size();
        for (ll i = 0; i < sz_a; i++) {
            ans[a[i]] = s1[i];
        }
        ll sz_b = b.size();
        for (ll i = 0; i < sz_b; i++) {
            ans[b[i]] = s2[i];
        }
        for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}