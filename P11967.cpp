#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n,m,tot=0,head[N],f[N][40],dep[N];
int val[N];
struct node
{
    int to, next;
} e[N * 4];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
}
void init()
{
    for(int i=1;i<=30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[j][i]=f[f[j][i-1]][i-1];
        }
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=30;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=30;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
void dfs2(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs2(v,x);
        val[x]+=val[v];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    init();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        int o=lca(x,y);
        val[x]++;
        val[y]++;
        val[f[o][0]]--;
        val[o]--;
    }
    dfs2(1,0);
    int x,y;
    cin>>x>>y;
    int o=lca(x,y),now=0;
    if(val[o]==0)now++;
    while(x!=o)
    {
        if(val[x]==0)
            now++;
        x=f[x][0];
    }
    while(y!=o)
    {
        if(val[y]==0)
            now++;
        y=f[y][0];
    }
    if(now==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else
    {
        cout<<now<<endl;
    }
    return 0;
}