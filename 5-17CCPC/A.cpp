#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = -1;
    for (int i = 1, j = 1; j <= m; i <<= 1, j++)
    {
        int cur = 2 * i - 1;
        if (cur >= n || cur + 1LL * i * (m - j) >= n)
        {
            ans = i;
            break;
        }
        if (cur + 1LL * (2 * i - 1) * (m - j) >= n)
        {
            ans = (n - cur - 1) / (m - j) + 1;
            break;
        }
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
