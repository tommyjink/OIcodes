#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot=0,head[N],in[N];
int dis[N],done[N];
struct node
{
    int to,next;
}e[N*2];
struct Point
{
    int dis,num;
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
void dijkstra()
{
    memset(dis,63,sizeof(dis));
    dis[n]=0;
    q.push((Point){0,n});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            in[v]--;
            if(t.dis+in[v]+1<dis[v])
            {
                dis[v]=t.dis+in[v]+1;
                q.push((Point){dis[v],v});
            }
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
        add(y,x);
        in[x]++;
    }
    dijkstra();
    cout<<dis[1]<<endl;
    return 0;
}