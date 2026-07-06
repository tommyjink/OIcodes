#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot=0,num=0;
int dfn[N],low[N],stk[N],top=0;
int col[N],cnt=0,f[N][40],dep[N];
vector<int> E[N];
struct node
{
    int to,next,from;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
void tarjan(int x,int fa)
{
    dfn[x]=low[x]=++num;
    stk[top++]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(!dfn[v])
        {
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
        }
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        ++cnt;
        while(1)
        {
            int t=stk[--top];
            col[t]=cnt;
            if(t==x)break;
        }
    }
}
void dfs(int x,int fa)
{
    f[x][0]=fa,dep[x]=dep[fa]+1;
    for(auto v:E[x])
        if(v!=fa)dfs(v,x);
}
void init()
{
    for(int i=1;i<=30;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
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
int dis(int x,int y)
{
    int o=lca(x,y);
    return dep[x]+dep[y]-2*dep[o]+1;
}
void binary(int x)
{
    vector<int> v;
    while(x)
    {
        v.push_back(x&1ll);
        x>>=1;
    }
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i];
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i,0);
    for(int i=1;i<=tot;i++)
        if(col[e[i].from]!=col[e[i].to])
            E[col[e[i].from]].push_back(col[e[i].to]);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<" ";
    dfs(1,0);
    init();
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        binary(dis(col[x],col[y]));
    }
    return 0;
}