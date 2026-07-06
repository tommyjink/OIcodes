#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int head[N],tot=0;
int n,m,dis[N],done[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
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
void dijkstra()
{
    q.push({1,1});
    for(int i=1;i<=n;i++)dis[i]=INF,done[i]=0;
    dis[1]=1;
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(max(dis[t.num],v)<dis[v])
            {
                dis[v]=max(dis[t.num],v);
                q.push({v,dis[v]});
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)head[i]=0;
    tot=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        if(dis[i]==INF)cout<<"-1 ";
        else cout<<dis[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}