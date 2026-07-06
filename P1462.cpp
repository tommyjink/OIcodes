#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,b,f[N],tot,head[N],dis[N],done[N];
int x[N],y[N],z[N];
struct node{int to,next,val;}e[N*10];
struct Point{int num,dis;};
bool operator <(Point x,Point y){return x.dis>y.dis;}
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dijkstra(int s)
{
    priority_queue<Point> q;
    for(int i=1;i<=n;i++)dis[i]=INF,done[i]=0;
    dis[s]=0;q.push((Point){s,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(t.dis+e[i].val<dis[v])
            {
                dis[v]=t.dis+e[i].val;
                q.push((Point){v,dis[v]});
            }
        }
    }
}
bool check(int mid)
{
    tot=0;
    for(int i=1;i<=n;i++)head[i]=0;
    for(int i=1;i<=m;i++)
        if(f[x[i]]<=mid&&f[y[i]]<=mid)add(x[i],y[i],z[i]),add(y[i],x[i],z[i]);
    dijkstra(1);
    return dis[n]<=b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    for(int i=1;i<=m;i++)
        cin>>x[i]>>y[i]>>z[i];
    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    if(l==1e9)cout<<"AFK"<<endl;
    else cout<<l<<endl;
    return 0;
}