#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=110;
int n,a[N],w[N][N],dp[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            w[i][j]=w[i][j-1]+(j-i!=a[j]);
    memset(dp,60,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int t=1;t<=i;t++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i][t]=min(dp[i][t],dp[j][t-1]+w[j+1][i]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dp[n][i]<<endl;
    return 0;
}