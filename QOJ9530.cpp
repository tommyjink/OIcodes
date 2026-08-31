#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,siz[N],sum[N],dep[N],ans=0;
vector<int> g[N];
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
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    siz[x]=1;
    for(int v:g[x])
    {
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
    }
    sum[x]=siz[x]*siz[x];
    for(int v:g[x])
        if(v!=fa)sum[x]=(sum[x]+sum[v])%P;
}
void dfs1(int x,int fa,int s)
{
    int tot=0;
    for(int v:g[x])
        if(v!=fa)tot=(tot+sum[v])%P;
    for(int v:g[x])
    {
        if(v==fa)continue;
        dfs1(v,x,((s+tot-sum[v]+(n-siz[x])*(n-siz[x])%P)%P+P)%P);
    }
    if(x==1)return;
    int t=n-siz[x];
    ans=(ans+(siz[x]*t%P)*(siz[x]*t%P)%P)%P;
    ans=(ans+s*siz[x]%P*siz[x]%P)%P;
    ans=(ans+t*t%P*tot%P)%P;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans=0;
    dfs(1,0);
    dfs1(1,0,0);
    int tmp=n*(n-1)%P*n%P*(n-1)%P*qpow(4,P-2)%P;
    cout<<ans*qpow(tmp,P-2)%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}