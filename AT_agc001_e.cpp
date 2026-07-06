#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,M=5005,P=1e9+7;
int n,a[N],b[N],dp[M][M],c[N],ic[N];
int qpow(int x,int y)
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
void init()
{
    c[0]=ic[0]=1;
    for(int i=1;i<N;i++)
        c[i]=c[i-1]*i%P;
    ic[N-1]=qpow(c[N-1],P-2);
    for(int i=N-2;i>=1;i--)
        ic[i]=ic[i+1]*(i+1)%P;
}
inline int C(int x,int y)
{
    return c[x]*ic[x-y]%P*ic[y]%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        dp[2001-a[i]][2001-b[i]]++;
    }
    for(int i=1;i<M;i++)
        for(int j=1;j<M;j++)
            dp[i][j]=((dp[i][j]+dp[i-1][j])%P+dp[i][j-1])%P;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[a[i]+2001][b[i]+2001])%P;
    for(int i=1;i<=n;i++)
        ans=((ans-C(2*a[i]+2*b[i],2*a[i]))%P+P)%P;
    ans=ans*qpow(2,P-2)%P;
    cout<<ans<<endl;
    return 0;
}