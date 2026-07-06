#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&(-x))
#define endl "\n"
using namespace std;
const int N=5020;
int n,P,dp[N][N];
int t[N*2];
inline void add(int x,int d)
{
    if(x<=0)return;
    for(int i=x;i<=2*n;i+=lowbit(i))
        t[i]=(t[i]+d)%P;
}
inline int sum(int x)
{
    if(x<=0)return 0;
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res=(res+t[i])%P;
    return res;
}
inline int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>P;
    dp[1][1]=1;
    add(2,1);
    for(int i=2;i<=n;i++)
    {
        dp[i][i]=qpow(2,i-2);
        for(int j=1;(j<<1)<i;j++)
        {
            dp[i][j]=dp[j][j]*sum(i-2*j-1)%P,
            dp[i][i]=((dp[i][i]-dp[i][j])%P+P)%P;
        }
        for(int j=1;j<=i;j++)
            add(i+j,dp[i][j]);
        // for(int j=1;j<=i;j++)
        //     printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
    }
    cout<<dp[n][n];
    return 0;
}