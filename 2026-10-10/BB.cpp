#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e6+10;
int n,tot,head[N];
int s,t,fa[N],val[N],f[N],dis[N];
int dep[N],vis[N],cnt=0,l[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dfs(int x)
{
    dep[x]=dep[fa[x]]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x])continue;
        fa[v]=x;
        val[v]=e[i].val;
        dfs(v);
    }
}
void dfs1(int x,int fa,int dep)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||vis[v])continue;
        dis[dep]=min(dis[dep],e[i].val);
        dfs1(v,x,dep+1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dis,127,sizeof(dis));
    memset(f,127,sizeof(f));
    cin>>n>>s>>t;
    for(int i=1;i<=n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    if(s==t)
    {
        for(int i=0;i<=n;i++)cout<<"0 ";
        return 0;
    }
    dfs(1);
    int x=s,y=t;
    if(dep[x]<dep[y])swap(x,y);
    while(dep[x]>dep[y])
    {
        vis[x]=true;
        l[++cnt]=val[x];
        x=fa[x];
    }
    while(x!=y)
    {
        vis[x]=vis[y]=true;
        l[++cnt]=val[x];
        l[++cnt]=val[y];
        x=fa[x],y=fa[y];
    }
    vis[x]=true;
    sort(l+1,l+1+cnt);
    int sum=0;
    for(int i=1;i<=cnt;i++)
        sum+=l[i],f[cnt-i]=sum;
    for(int i=1;i<=n;i++)
        if(vis[i])dfs1(i,0,0);
    for(int i=1;cnt+i+2<=n;i++)
    {
        dis[i]=min(dis[i],dis[i-1]);
        f[cnt+i+2]=f[cnt]-l[1]+dis[i];
    }
    int res=1e18;
    for(int i=0;i<=n;i++)
    {
        res=min(res,f[i]);
        cout<<res<<" ";
    }
    return 0;
}