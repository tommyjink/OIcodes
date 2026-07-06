#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 100;
int n, cnt = 0, pri[N], vis[N], phi[N], f[N];
void init()
{
    phi[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
            pri[++cnt] = i, phi[i] = i - 1;
        for (int j = 1; j <= cnt; j++)
        {
            if (pri[j] * i >= N)
                break;
            vis[i * pri[j]] = true;
            if (i % pri[j] == 0)
            {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            phi[i * pri[j]] = phi[i] * phi[pri[j]];
        }
    }
    for (int n = 1; n < N; n++)
    {
        for (int i = n; i < N; i += n)
        {
            f[i]+=(phi[n]*n+1)/2;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << f[n] * n << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    // for(int i=1;i<=100;i++)
    //     cout<<phi[i]<<" ";
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}