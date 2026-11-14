#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,P=998244353;
int n,tot,head[N],fa[N] ;
int a[N],b[N],in[N],siz[N];
int dp[N],fac[N],inv[N];
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
    if(x<y||x<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
    in[y]++;
}
void dfs(int x,int fa)
{
    dp[x]=1;
    siz[x]=1;
    int now=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
        now+=siz[v];
        dp[x]=dp[x]*dp[v]%P*C(now,siz[v])%P;
    }
}
void solve()
{
    cin>>n;
    for(int i=0;i<=n+1;i++)
        head[i]=siz[i]=in[i]=0;
    tot=0;
    for(int i=2;i<=n;i++)
        cin>>fa[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=2;i<=n;i++)
        if(b[i]>a[fa[i]]||a[i]>b[fa[i]])add(fa[i],i);
    for(int i=1;i<=n;i++)
        if(!in[i])add(n+1,i);
    dfs(n+1,0);
    cout<<dp[n+1]<<endl;
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
    int t;cin>>t;
    while(t--)solve();
    return 0;
}