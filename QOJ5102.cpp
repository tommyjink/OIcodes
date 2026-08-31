#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2005,INF=1e18;
int n,q,dis[N][N],nxt[N][N],dfn[N][N],r[N][N];
int f[N][21],dep[N],nfd[N][N],pre[N][N],suf[N][N];
int tot[N],W=0;
vector<pii> g[N];
void dfs1(int x,int fa,int rt,int now)
{
    dfn[rt][x]=++tot[rt];
    nfd[rt][tot[rt]]=x;
    dis[rt][x]=now;
    for(auto [v,val]:g[x])
    {
        if(v==fa)continue;
        dfs1(v,x,rt,now+val);
        nxt[v][rt]=x;
    }
    r[rt][x]=tot[rt];
}
void dfs(int x,int fa)
{
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(auto [v,val]:g[x])
    {
        if(v==fa)continue;
        dfs(v,x);
    }
}
void init()
{
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    
    for(int i=1;i<=n;i++)
    {
        pre[i][0]=suf[i][n+1]=0;
        for(int j=1;j<=n;j++)
            pre[i][j]=max(pre[i][j-1],dis[i][nfd[i][j]]);
        for(int j=n;j>=1;j--)
            suf[i][j]=max(suf[i][j+1],dis[i][nfd[i][j]]);
    }
}
int lca1(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int lca(int rt,int x,int y)
{
    int p1=lca1(rt,x);
    int p2=lca1(rt,y);
    int p3=lca1(x,y);
    int res=p1;
    // cout<<p1<<"//"<<p2<<"//"<<p3<<endl;
    if(dep[p2]>dep[res])res=p2;
    if(dep[p3]>dep[res])res=p3;
    return res;
}
int far(int x,int c)
{
    if(c==0)return pre[x][n];
    return max(pre[x][dfn[x][c]-1],suf[x][r[x][c]+1]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
        W+=z;
    }
    for(int i=1;i<=n;i++)
        dfs1(i,0,i,0);
    dfs(1,0);
    init();
    // while(1)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     cout<<lca1(x,y)<<endl;
    // }
    while(q--)
    {
        int s,k,t;
        cin>>s>>k>>t;
        int L=lca(k,s,t);
        // cout<<L<<"!"<<endl;
        if(L==t){cout<<"impossible"<<endl;continue;}
        int ans=2*W-far(s,nxt[L][k]);
        ans=min(ans,2*W-dis[s][L]+dis[L][k]-far(k,L));
        cout<<ans<<endl;
    }
    return 0;
}