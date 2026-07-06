#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,cnt=0,dis[N],done[N];
int tot=0,head[N];
struct node
{
    int to,next,val;
}e[N*5];
struct Point
{
    int num,dis;
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
map<int,int> mp;
int num(int x)
{
    if(!mp.count(x))mp[x]=++cnt;
    return mp[x];
}
priority_queue<Point> q;
void dijkstra(int s)
{
    while(!q.empty())q.pop();
    q.push((Point){s,0});
    for(int i=1;i<=n;i++)dis[i]=INF,done[i]=0;
    dis[s]=0;
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
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        z=num(z);
        add(z+n,x,0);
        add(x,z+n,1);
        add(z+n,y,0);
        add(y,z+n,1);
    }
    int s,t;
    cin>>s>>t;
    n+=cnt;
    dijkstra(s);
    cout<<dis[t]<<endl;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=0;
    mp.clear();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}