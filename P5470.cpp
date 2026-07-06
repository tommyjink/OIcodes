#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=155;
int t,n,K,L,a[N],b[N],dp[N][N][N];
void solve()
{
    memset(dp,0,sizeof(dp));
    cin>>n>>K>>L;
    int ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int now=1;now<=n;now++)
    {
        for(int i=now;i>=0;i--)
        {
            for(int j=now;j>=0;j--)
            {
                for(int k=min({i,j});k>=0;k--)
                {
                    if(i&&j&&k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+a[now]+b[now]);
                    if(j)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+b[now]);
                    if(i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[now]);
                    if(k>=L&&i==K&&j==K)ans=max(ans,dp[i][j][k]);
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)
        solve();
    return 0;
}