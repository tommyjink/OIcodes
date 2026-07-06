#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
int n, a[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int maxval = -1e9, now = 1e9, ans = 1e9, val = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            
        }
        now = min(now, a[i]);
        val += now;
        if(i>1)maxval = max(maxval, a[i] - a[i - 1]);
    }
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