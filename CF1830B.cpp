#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N], tag[N];
// a[i]*a[j]=b[i]+b[j]
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int limit = sqrt(2 * n),ans=0;
    for (int i=1;i<=limit;i++)
    {
        for(int j=1;j<=n;j++)
            tag[j]=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)
            {
                if(a[j]*i-b[j]<=n&&a[j]*i-b[j]>=1)
                    ans+=tag[a[j]*i-b[j]];
                tag[b[j]]++;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(a[j]>i)
            {
                if(a[j]*i-b[j]<=n&&a[j]*i-b[j]>=1)
                    ans+=tag[a[j]*i-b[j]];
            }
        }
    }
    cout<<ans<<endl;
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