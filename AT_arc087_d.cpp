#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005,P=1e9+7;
int n,tot,head[N];
int siz[N],rt=0;
int fac[N],inv[N],dp[N];
struct node
{
    int to,next;
}e[N*2];
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
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
int f(int siz,int x)
{
    return C(siz,x)*C(siz,x)%P*fac[x]%P;
}
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    siz[x]=1;
    int tag=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        if(siz[v]>n/2)tag=0;
        siz[x]+=siz[v];
    }
    if(n-siz[x]>n/2)tag=0;
    if(tag)rt=x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    dfs(rt,0);
    dp[0]=1;
    for(int i=head[rt];i;i=e[i].next)
    {
        int v=e[i].to;
        for(int j=n;j>=0;j--)
        {
            for(int k=1;k<=min(j,siz[v]);k++)
            {
                dp[j]=(dp[j]+dp[j-k]*f(siz[v],k)%P)%P;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(i&1)ans=(ans-dp[i]*fac[n-i]%P+P)%P;
        else ans=(ans+dp[i]*fac[n-i]%P+P)%P;
    }
    cout<<ans<<endl;
    return 0;
}