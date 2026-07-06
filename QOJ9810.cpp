#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e18;
int n,m,q,dis[N],tag[N];
int dfn[N],low[N],num=0;
int col[N],stk[N],top=0,cnt=0;
int tot,head[N],arr[N],vis[N];
vector<int> g[N];
struct node
{
    int to,from,next,val;
}e[N*5];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,x,head[x],z};
    head[x]=tot;
}
void tarjan(int x)
{
    stk[top++]=x;
    dfn[x]=low[x]=++num;
    for(int i=head[x];~i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(!col[v])
        {
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x])
    {
        cnt++;
        while(1)
        {
            int t=stk[--top];
            col[t]=cnt;
            if(t==x)break;
        }
    }
}
bool dfs(int x,int now)
{
    // cout<<x<<endl;
    for(int i=head[x];~i;i=e[i].next)
    {
        int v=e[i].to;
        if(col[v]!=now)continue;
        if(dis[v]==INF)
        {
            dis[v]=dis[x]+e[i].val;
            if(dfs(v,now))return true;
        }
        else if(dis[x]+e[i].val!=dis[v])return true;
    }
    return false;
}
void dfs1(int x)
{
    if(vis[x])return;
    vis[x]=true;
    if(tag[x])
    {
        arr[x]=true;
        return;
    }
    for(auto v:g[x])
    {
        if(!vis[v])dfs1(v);
        arr[x]|=arr[v];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        x=(x%n+n)%n;
        add(x,((x+y)%n+n)%n,y);
    }
    for(int i=0;i<=n-1;i++)
        if(!dfn[i])tarjan(i);
    for(int i=0;i<=n-1;i++)
        dis[i]=INF;
    for(int i=0;i<=n-1;i++)
        if(dis[i]==INF)
            dis[i]=0,tag[col[i]]=dfs(i,col[i]);
    for(int i=1;i<=tot;i++)
        if(col[e[i].from]!=col[e[i].to])
            g[col[e[i].from]].push_back(col[e[i].to]);
    while(q--)
    {
        int x;
        cin>>x;
        x=(x%n+n)%n;
        dfs1(col[x]);
        if(arr[col[x]])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}