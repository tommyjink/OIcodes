#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e3 + 100;
int n, a[N], dp[N], cnt[N], ans = 0, tot = 0, vis[N];
vector<int> v;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("P1108_10.in","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], dp[i] = cnt[i] = 1, v.push_back(a[i]);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[i] < a[j] && !vis[a[j]])
            {
                vis[a[j]] = true;
                if (dp[j] + 1 == dp[i])
                    cnt[i] += cnt[j];
                else if (dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1, cnt[i] = cnt[j];
            }
        }
        ans = max(ans, dp[i]);
        memset(vis, 0, sizeof(vis));
    }
    for (int i = n; i >= 1; i--)
        if (dp[i] == ans && !vis[a[i]])
            tot += cnt[i], vis[a[i]] = true;
    cout << ans << " " << tot << endl;
    return 0;
}