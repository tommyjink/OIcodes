#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=55,P=998244353;
int n,m,K,w[N],dp[N][N][N],c[N][N],sum=0;
int qpow(int x,int y)
{
    x%=P;
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
int F(int x)
{
    return qpow(x,P-2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++)
        cin>>w[i],sum+=w[i];
    for(int i=1;i<=K;i++)
    {
        c[i][1]=i%P;
        for(int j=2;j<=i;j++)
        {
            c[i][j]=c[i][j-1]*(i-j+1)%P*F(j)%P;
            // printf("c[%lld][%lld]=%lld\n",i,j,c[i][j]);
        }
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0][0]=dp[i-1][0][0];
        for(int j=1;j<=K;j++)
        {
            for(int k=1;k<=i;k++)
            {
                dp[i][j][k]=dp[i-1][j][k];
                for(int p=1;p<=j;p++)
                {
                    dp[i][j][k]=(dp[i][j][k]+c[j][p]%P*qpow(w[i]*F(sum)%P,p)%P*dp[i-1][j-p][k-1]%P)%P;
                } 
            }
        }
    }
    cout<<dp[n][K][m]<<endl;
    return 0;
}