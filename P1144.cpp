#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16,P=1e5+3;
int n,m,tot=0,head[N];
int dis[N],done[N],cnt[N];
struct node
{
    int to,next;
}e[N*10];
struct Point
{
    int num,dis;
};
bool operator <(Point x,Point y)
{
    return x.dis>y.dis;
}
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
priority_queue<Point> q;
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)dis[i]=INF,done[i]=0;
    q.push((Point){s,0});
    cnt[1]=1;
    dis[s]=0;
    while(!q.empty())
    {
        Point t=q.top();
        q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(t.dis+1<dis[v])
            {
                dis[v]=t.dis+1;
                q.push((Point){v,dis[v]});
                cnt[v]=cnt[t.num];
            }
            else if(t.dis+1==dis[v])cnt[v]=(cnt[v]+cnt[t.num])%P;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
        cout<<cnt[i]<<endl;
    return 0;
}