#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 3e6 + 10, M = 25;
int n, a[N], nxt[N], g[M][N], f[N];
void print(int x)
{
    for (int i = 1; i <= 20; i++)
        cout << ((x & (1ll << (i - 1))) ? "1 " : "0 ");
    cout << endl;
}
map<int, int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]] = 1;
    for (int i = 1; i <= 20; i++)
    {
        if (!mp[i])
            continue;
        int now = 0;
        for (int j = n; j >= 1; j--)
        {
            nxt[j] = now, g[i][j] = nxt[nxt[j]];
            if (a[j] == i)
                now = j, g[i][j] = nxt[j];
        }
    }
    memset(f, 127, sizeof(f));
    int ans = 0;
    f[0] = 0;
    for (int i = 0; i < (1ll << 20); i++)
    {
        if (i == 0 || f[i] < 1e18)
            for (int j = 1; j <= 20; j++)
            {
                if (!g[j][f[i] + 1] || (i & (1ll << (j - 1))) || !mp[j])
                    continue;
                int now = (i | (1ll << (j - 1)));
                f[now] = min(f[now], g[j][f[i] + 1]);
                if (f[now])
                    ans = max(ans, __builtin_popcountll(now) * 2ll);
            }
    }
    cout << ans << endl;
    return 0;
}