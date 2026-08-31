#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e16;
int n,m,tot,head[N],f[N][21],dis[N];
int dep[N],cnt=0,fa[N],h[N],done[N];
struct node
{
    int to,next,from;
}e[N*2];
struct node1
{
    int x,y,z;
}E[N];
bool cmp(node1 x,node1 y)
{
    return x.z<y.z;
}
int getfa(int x)
{
    if(x==fa[x])return x;
    return fa[x]=getfa(fa[x]);
}
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
void bfs(int s)
{
    for(int i=1;i<=n;i++)dep[i]=-1;
    dep[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        // cout<<t<<"!"<<endl;
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(v==f[t][0])continue;
            if(~dep[v])
            {
                if(t<v)E[++cnt]={t,v,dep[t]+dep[v]+1};
                continue;
            }
            f[v][0]=t;
            dep[v]=dep[t]+1;
            q.push(v);
        }
    }
}
void init()
{
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
struct Point
{
    int num,dis;
};
bool operator <(Point x,Point y)
{
    return x.dis>y.dis;
}
priority_queue<Point> q;
void dijkstra(int s)
{
    q.push({s,0});
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    dis[s]=0;
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        // cout<<t.num<<"!"<<endl;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            int d=max(dis[t.num]+1,h[v]);
            if(d<dis[v])
            {
                dis[v]=d;
                q.push({v,dis[v]});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    bfs(n);init();
    for(int i=1;i<=n;i++)h[i]=INF;
    sort(E+1,E+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int x=E[i].x,y=E[i].y,val=E[i].z;
        int o=lca(x,y);
        // cout<<x<<" "<<y<<" "<<z<<" "<<o<<" "<<val<<endl;
        while(dep[getfa(x)]>dep[o])
        {
            x=getfa(x);
            // cout<<x<<"!"<<endl;
            h[x]=val-dep[x];
            fa[x]=getfa(f[x][0]);
        }
        while(dep[getfa(y)]>dep[o])
        {
            y=getfa(y);
            h[y]=val-dep[y];
            fa[y]=getfa(f[y][0]);
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<h[i]<<endl;
    dijkstra(n);
    if(dis[1]>=INF)cout<<"-1"<<endl;
    else cout<<dis[1]<<endl;
    return 0;
}