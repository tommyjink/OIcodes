#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot,s,dis[N],done[N];
struct node
{
    int to,next,val;
}e[N*2];
struct Point
{
    int num,dis;
};
bool operator >(Point a,Point b)
{
    return a.dis>b.dis;
}
priority_queue<Point,vector<Point>,greater<Point> >q;
void add(int u,int v,int w)
{
    e[++tot].to=v;
    e[tot].val=w;
    e[tot].next=head[u];
    head[u]=tot;
}
void dijkstra()
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push((Point){s,0});
    while(!q.empty())
    {
        Point now=q.top();q.pop();
        if(done[now.num]) continue;
        done[now.num]=1;
        for(int i=head[now.num];i;i=e[i].next)
        {
            if(done[e[i].to]) continue;
            if(dis[e[i].to]>dis[now.num]+e[i].val)
            {
                dis[e[i].to]=dis[now.num]+e[i].val;
                q.push((Point){e[i].to,dis[e[i].to]});
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
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }

    return 0;
}