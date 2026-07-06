#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,k,s,t,tot,head[N],dis[N*10],done[N];
struct node{int to,next,val;}e[N*10];
struct Point{int num,dis;};
bool operator <(Point x,Point y){return x.dis>y.dis;}
inline int cal(int x,int k)
{
    return x+(k-1)*n;
}
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dijkstra(int s)
{
    priority_queue<Point> q;
    for(int i=1;i<=(k+2)*n;i++)dis[i]=INF,done[i]=0;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k>>s>>t;
    s++,t++;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x++,y++;
        for(int i=1;i<=k+1;i++)
            add(cal(x,i),cal(y,i),z),
            add(cal(y,i),cal(x,i),z);
        for(int i=2;i<=k+1;i++)
            add(cal(x,i-1),cal(y,i),0),
            add(cal(y,i-1),cal(x,i),0);
    }
    dijkstra(cal(s,1));
    int ans=1e18;
    for(int i=1;i<=k+1;i++)ans=min(ans,dis[cal(t,i)]);
    cout<<ans;
    return 0;
}