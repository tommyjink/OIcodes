#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=50,M=1e5+10,P=1e9+7;
const int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int n,m,fac[M],invfac[M],ans=0;
int a[N],b[N],cnt=0,now=0,dp[N][M];
int initdone=false;
bool checkprime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return false;
    return true;
}
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
    fac[0]=1;
    for(int i=1;i<M;i++)
        fac[i]=i*fac[i-1]%P;
    invfac[M-1]=qpow(fac[M-1],P-2);
    for(int i=M-2;i>=0;i--)
        invfac[i]=invfac[i+1]*(i+1)%P;
}
int C(int x,int y)
{
    if(!initdone)init(),initdone=true;
    return fac[x]*invfac[x-y]%P*invfac[y]%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=2;i<=m;i++)
    {
        if(checkprime(i)&&i>50)cnt++;
        else a[++now]=i;
    }
    // int tmp=C(n,cnt)*fac[cnt]%P;
    // n-=cnt;
    for(int i=1;i<=now;i++)
    {
        for(int j=1;j<=15;j++)
            if(a[i]%prime[j]==0)
                b[i]|=(1ll<<(j-1));
    }
    dp[0][0]=1;
    for(int i=1;i<=now;i++)
    {
        for(int s=0;s<(1ll<<15);s++)
        {
            if(!(s&b[i]))
            {
                for(int j=0;j<15;j++)
                {
                    dp[j+1][s|b[i]]=(dp[j+1][s|b[i]]+dp[j][s])%P;
                }
            }
        }
    }
    for(int i=0;i<=min(15ll,n);i++)
    {
        int res=0;
        for(int j=0;j<(1ll<<15);j++)
            res=(res+dp[i][j])%P;
        // cout<<i<<" "<<res<<endl;
        int ss=0;
        for(int j=0;j<=min(n-i,cnt);j++)
            ss=(ss+C(n-i,j)*C(cnt,j)%P)%P;
        ans=(ans+C(n,i)*res%P*fac[i]%P*ss%P)%P;
    }
    cout<<ans%P<<endl;
    
    return 0;
}