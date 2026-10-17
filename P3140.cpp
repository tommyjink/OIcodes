#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=305,INF=1e16;
int n,K,r[N],a[N],dp[N][8],w[N][N];
int cal()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=7;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int t=1;t<=K;t++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i][t]=min(dp[i][t],dp[j][t-1]+w[j+1][i]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=K;j++)
            ans+=dp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
        {
            if(dp[i][j]>K)return -1;
        }
    return dp[n][K];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>K;
    for(int i=1;i<=n;i++)
        cin>>r[i],r[i+n]=r[i];
    int ans=INF;
    for(int s=1;s<=n;s++)
    {
        for(int j=1;j<=n;j++)
            a[j]=r[s+j-1];
        for(int j=1;j<=n;j++)
            for(int k=j;k<=n;k++)
                w[j][k]=w[j][k-1]+(k-j)*a[k];
        int tmp=cal();
        if(~tmp)ans=min(ans,tmp);
        else continue;
        ans=min(ans,cal());
    }
    cout<<ans<<endl;
    return 0;
}