#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,tot,head[N],S;
int dis[N][2],done[N][2];
struct node
{
    int to,next,val;
}e[N*2];
struct Point
{
    int num,dis,k;
};
bool operator <(Point x,Point y)
{
    return x.dis>y.dis;
}
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
        dis[i][0]=dis[i][1]=INF,
        done[i][0]=done[i][1]=0;
    priority_queue<Point> q;
    dis[s][0]=0;
    q.push({s,0,0});
    if(s==S)dis[s][1]=0,q.push({s,0,1});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num][t.k])continue;
        done[t.num][t.k]=1;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].val<t.dis)continue;
            if(t.k==1&&!done[v][1]&&e[i].val<dis[v][1])
                dis[v][1]=e[i].val,q.push({v,dis[v][1],1});
            if(t.k==0&&!done[v][0]&&e[i].val<dis[v][0])
                dis[v][0]=e[i].val,q.push({v,dis[v][0],0});
            if(t.k==0&&v==S&&!done[v][1]&&e[i].val<dis[v][1])
                dis[v][1]=e[i].val,q.push({v,dis[v][1],1});
        }
    }
}
struct query
{
    int x,y,id;
}a[N];
int q,ans[N];
bool cmp(query x,query y)
{
    return x.x<y.x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>S;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    cin>>q;
    for(int i=1;i<=q;i++)
        cin>>a[i].x>>a[i].y,a[i].id=i;
    sort(a+1,a+q+1,cmp);
    for(int i=1;i<=q;i++)
    {
        if(i==1||a[i].x!=a[i-1].x)dijkstra(a[i].x);
        ans[a[i].id]=(dis[a[i].y][1]==INF?-1:dis[a[i].y][1]);
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
    return 0;
}