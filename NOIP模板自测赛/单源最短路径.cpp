#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,s,tot,head[N],dis[N],done[N];
struct node
{
    int to,next,val;
}e[N*2];
struct Point
{
    int num,dis;
};
bool operator <(const Point &x,const Point &y)
{
    return x.dis>y.dis;
}
priority_queue<Point> q;
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dijkstra(int s)
{
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)
        dis[i]=INF,done[i]=0;
    dis[s]=0;
    q.push((Point){s,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(dis[t.num]+e[i].val<dis[v])
            {
                dis[v]=dis[t.num]+e[i].val;
                q.push((Point){v,dis[v]});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}