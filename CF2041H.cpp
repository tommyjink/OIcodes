#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,k,dp[N][2],t0[N],t1[N],ans=0,b[N],c[N];
int qpow(int x,int y)
{
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
void add(int *t,int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]=(t[i]+d)%P;
}
int query(int *t,int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res=(res+t[i])%P;
    return res;
}
int sum(int *t,int l,int r)
{
    if(l>r)return 0;
    return ((query(t,r)-query(t,l-1))%P+P)%P;
}
int C(int x,int y)
{
    return b[x]*c[y]%P*c[x-y]%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    b[0]=1,c[0]=F(1);
    for(int i=1;i<N;i++)
    {
        b[i]=b[i-1]*i%P;
        c[i]=c[i-1]*F(i)%P;
    }
    cin>>n>>k;
    dp[1][0]=dp[1][1]=1;
    add(t0,1,1);
    add(t1,1,1);
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=sum(t1,max(1ll,i-k+1),i-1)%P;
        dp[i][1]=sum(t0,max(1ll,i-k+1),i-1)%P;
        add(t0,i,dp[i][0]);
        add(t1,i,dp[i][1]);
    }
    for(int i=2;i<=n;i++)
        ans=(ans+((dp[i][0]+dp[i][1])%P)*C(n-1,i-1))%P;
    cout<<(ans+1)%P<<endl;
    return 0;
}