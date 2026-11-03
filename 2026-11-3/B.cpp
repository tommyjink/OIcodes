#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005,P=998244353;
signed n,tot,head[N];
signed dep[N],lg[N*2],st[N*2][21],pos[N],q[N*2],num=0,rt[N];
signed f[N][N],g[N][N];
int h[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    q[++num]=x;
    pos[x]=num;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        q[++num]=x;
    }
}
void init()
{
    for(int i=2;i<=num;i++)
        lg[i]=lg[i/2]+1;
    for(int i=1;i<=num;i++)
        st[i][0]=q[i];
    for(int i=1;(1<<i)<=num;i++)
    {
        for(int j=1;j<=num-(1<<i)+1;j++)
        {
            if(dep[st[j][i-1]]<dep[st[j+(1<<(i-1))][i-1]])
                st[j][i]=st[j][i-1];
            else st[j][i]=st[j+(1<<(i-1))][i-1];
        }
    }
}
int query(int l,int r)
{
    if(l==r)return st[l][0];
    if(l>r)return -1;
    int d=lg[r-l+1];
    if(dep[st[l][d]]<dep[st[r-(1<<d)+1][d]])
        return st[l][d];
    return st[r-(1<<d)+1][d];
}
int lca(int x,int y)
{
    x=pos[x],y=pos[y];
    if(x>y)swap(x,y);
    return query(x,y);
}
int dis(int x,int y)
{
    int o=lca(x,y);
    return dep[x]+dep[y]-2*dep[o];
}
void dfs1(int x,int fa)
{
    rt[dep[x]]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs1(v,x);
        h[x]=h[x]*(h[v]+1)%P;
        for(int j=3;j<=n;j+=2)
        {
            f[x][j]=1ll*f[x][j]*(g[x][j]+1)%P;
            g[x][j]=0;
        }
    }
    for(int i=3;i<dep[x];i+=2)
    {
        int o=rt[dep[x]-i];
        g[o][i]=(g[o][i]+f[x][i])%P;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    init();
    for(int i=3;i<=n;i+=2)
        for(int j=1;j<=n;j++)
            f[j][i]=1;
    for(int i=1;i<=n;i++)
        h[i]=1;
    dfs1(1,0);
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        ans=(ans+h[x])%P;
        for(int d=3;d<=n;d+=2)
            ans=(ans+f[x][d]-1+P)%P;
        for(int y=x+1;y<=n;y++)
        {
            int o=lca(x,y);
            if(o==x||o==y)continue;
            int d=dep[x]+dep[y]-2*dep[o];
            if(d<3||d%2==0)continue;
            ans=(ans+1ll*f[x][d]*f[y][d])%P;
        }
    }
    cout<<ans<<endl;
    return 0;
}
