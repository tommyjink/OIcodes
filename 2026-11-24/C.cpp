#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], b[N];
multiset<int> s;
vector<int> g[N], f[N];
void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        g[i].clear(), f[i].clear();
    s.clear();
    int base = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] < b[i])
            g[a[i]].push_back(n - b[i] + 1), base++;
        else
            f[b[i]].push_back(n - a[i] + 1);
    }
    for (int x = 1; x <= n - 1; x++)
    {
        for (int y : g[x])
            s.insert(y);
        for (int y : f[x])
            base++;
        for (int y : f[x])
        {
            auto p = s.lower_bound(y);
            if (p != s.end())
                s.erase(p), base--;
        }
        while (!s.empty() && *prev(s.end()) > n - x)
            s.erase(prev(s.end())), base--;
        cout << base << " ";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}