#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e12;
int n,m,in[N],tag[N],ans=0;
int head[N],tot,dis[N],vis[N];
vector<int> l;
vector<pii> g[N];
struct node
{
    int to,next,from;
}e[N*2];
struct DSU
{
    int fa[N];
    int getfa(int x)
    {
        return x==fa[x]?x:(fa[x]=getfa(fa[x]));
    }
    void merge(int x,int y)
    {
        x=getfa(x);
        y=getfa(y);
        if(x!=y)fa[x]=y;
    }
    void init()
    {
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
}D;
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
    in[y]++;
}
void topo()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        l.push_back(t);
        tag[t]=true;
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(!--in[v])q.push(v);
        }
    }
}
void bfs()
{
    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        if(!tag[i])q.push_back(i),dis[i]=0;
        else dis[i]=INF;
        vis[i]=0;
        // cout<<dis[i]<<" ";
    }
    // cout<<endl;
    while(!q.empty())
    {
        int t=q.front();q.pop_front();
        if(vis[t])continue;
        vis[t]=1;
        for(auto [v,val]:g[t])
        {
            if(vis[v])continue;
            if(dis[t]+val<dis[v])
            {
                dis[v]=dis[t]+val;
                if(val==0)
                {
                    q.push_front(v);
                }
                else
                {
                    q.push_back(v);
                }
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        head[i]=in[i]=tag[i]=vis[i]=0,g[i].clear();
    tot=ans=0;
    l.clear();
    D.init();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        D.merge(x,y);
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    // for(int i=1;i<=n;i++)
    //     cout<<in[i]<<"|";
    // cout<<endl;
    topo();
    for(int i=1;i<=n;i++)
        if(!tag[i])vis[D.getfa(i)]=true;
    for(int i=1;i<=n;i++)
        if(i==D.fa[i]&&!vis[i]){cout<<"-1"<<endl;return;}
    bfs();
    for(int i=1;i<=n;i++)
        ans+=dis[i];
    // cout<<endl;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}