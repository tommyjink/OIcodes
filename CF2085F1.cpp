#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int N = 3e3 + 10;
int n, k, a[N], l[N], r[N], b[N], col[N];
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        col[i] = 0;
    int cnt = 0, L = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!col[a[i]])
            cnt++;
        col[a[i]]++;
        if (!L&&cnt == (k - 1) / 2)
            L = i,cout<<L<<endl;
    }
    int m = ((k - 1) / 2) * ((k - 1) / 2 + 1);
    if (k % 2 == 0)
        m += k / 2;
    // cout<<m<<endl;
    int ans = 1e9;
    for (int i = L; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            l[j] = 1e9, r[j] = 1e9;
        for (int j = 1; j <= i; j++)
            l[a[j]] = min(l[a[j]], i - j);
        for (int j = i ; j <= n; j++)
            r[a[j]] = min(r[a[j]], j - i);
        for (int j = 1; j <= k; j++)
            b[j] = l[j] - r[j];
        sort(b + 1, b + 1 + k);
        // for(int j=1;j<=k;j++)
        //     cout<<b[j]<<" ";
        // cout<<endl;
        // for(int j=1;j<=k;j++)
        //     cout<<l[j]<<" ";
        // cout<<endl;
        // for(int j=1;j<=k;j++)
        //     cout<<r[j]<<" ";
        // cout<<endl;
        int res = 0;
        for (int j = 1; j <= k; j++)
            res += r[j];
        for (int j = 1; j <= (k - 1) / 2; j++)
            res += b[j];
        ans = min(ans, res - m);
        if (k % 2 == 0)
            res += b[k / 2];
        ans = min(ans, res - m);
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