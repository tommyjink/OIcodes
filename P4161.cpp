#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,prime[N],vis[N],cnt=0;
int dp[N][N];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x;
        x=x*x;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])prime[++cnt]=i;
        for(int j=i*i;j<=n;j+=i)
            vis[j]=true;
    }
    dp[0][0]=1;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];
            for(int k=1;j-qpow(prime[i],k)>=0;k++)
            {
                dp[i][j]+=dp[i-1][j-qpow(prime[i],k)];
            }
            // printf("dp[%lld][%lld]=%lld,%lld\n",i,j,dp[i][j],prime[i]);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        ans+=dp[cnt][i];
    cout<<ans<<endl;
    return 0;
}