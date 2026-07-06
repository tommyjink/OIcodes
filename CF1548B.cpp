#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5+10, M = 20;
int n, b[N], a[N], f[N][M + 5], g[N][M + 5];
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int mgcd(int l, int r)
{
    int res = a[l];
    for (int i = M; i >= 0; i--)
        if (f[l][i] <= r)
            res = gcd(res, g[l][i]),
            l = f[l][i];
    return res;
}
void solve()
{
    int ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i], a[i] = abs(b[i] - b[i - 1]), f[i][0] = i + 1, g[i - 1][0] = gcd(a[i - 1], a[i]);
    a[0]=a[n+1]=0,g[n][0] = a[n],f[n+1][0]=n+1,f[0][0]=1;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= n+1; j++)
            f[j][i] = f[f[j][i - 1]][i - 1],
            g[j][i] = gcd(g[j][i - 1], g[f[j][i - 1]][i - 1]);
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    // while (1)
    // {
    //     int l, r;
    //     cin >> l >> r;
    //     cout << mgcd(l, r) << endl;
    // }
    for (int i = 2, j = 2; i <= n; i++)
    {
        while (j <= i && mgcd(j, i) == 1)
            j++;
        ans = max(ans, i - j + 2);
    }
    cout << ans << endl;
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
// 1 0 0 0 0 0 0