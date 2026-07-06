#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,a[N],b[N],t,tot=0,head[N],dis[N],done[N];
struct node{int to,next,val;}e[N*2];
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
void solve()
{
    cin>>n;
    tot=0;
    for(int i=1;i<=n;i++)head[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        add(i,b[i],a[i]);
        if(i>1)add(i,i-1,0);
    }
    dijkstra(1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
        ans=max(ans,a[i]-dis[i]);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)solve();
    return 0;
}