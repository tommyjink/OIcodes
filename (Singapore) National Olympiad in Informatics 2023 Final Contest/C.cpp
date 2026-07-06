#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,tot,head[N],done[N];
int a[N],dis1[N],dis2[N],vis1[N],vis2[N];
struct node{int to,next,val;}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]={y,head[x],z};
    head[x]=tot;
}
struct Point{int num,dis,vis;};
bool operator <(Point x,Point y)
{
    if(x.dis==y.dis)return x.vis>y.vis;
    return x.dis>y.dis;
}
priority_queue<Point> q;
void dijkstra(int s,int *dis,int *vis)
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    for(int i=1;i<=n;i++)done[i]=false;
    dis[s]=0;
    q.push({s,0,a[s]});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to,val=max(t.dis+e[i].val,a[v]);
            if(done[v])continue;
            if(val<dis[v]||max(t.vis,a[v])<vis[v])
            {
                dis[v]=val;
                vis[v]=max(t.vis,a[v]);
                q.push({v,dis[v],max(t.vis,vis[v])});
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
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y,1);
        add(y,x,1);
    }
    dijkstra(1,dis1,vis1);
    dijkstra(n,dis2,vis2);
    int ans=INF;
    // for(int i=1;i<=n;i++)
    //     cout<<dis1[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<dis2[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(dis1[i]>=vis2[i]&&vis1[i]<=vis2[i])ans=min(ans,dis1[i]+dis2[i]);
        if(vis2[i]<=vis1[i]&&dis2[i]>=vis1[i])ans=min(ans,dis1[i]+dis2[i]);
        if(dis1[i]<vis2[i])ans=min(ans,dis1[i]+dis2[i]+vis2[i]-dis1[i]);
        if(dis2[i]<vis1[i])ans=min(ans,dis1[i]+dis2[i]+vis1[i]-dis2[i]);
    }
    cout<<ans<<endl;
    return 0;
}