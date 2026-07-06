#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot=0,dis[N],done[N];
struct node
{
    int to,next,val;
}e[N*2];
struct point
{
    int num,dis;
};
bool operator >(point x,point y)
{
    return x.dis>y.dis;
}
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
priority_queue<point,vector<point>,greater<point> > q;
void dijkstra()
{
    memset(dis,63,sizeof(dis));
    dis[n+1]=0;
    q.push((point){n+1,0});
    while(!q.empty())
    {
        point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(dis[t.num]+e[i].val<dis[v])
            {
                dis[v]=dis[t.num]+e[i].val;
                q.push((point){v,dis[v]});
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
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,2*z);
        add(y,x,2*z);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        add(n+1,i,x);
        add(i,n+1,x);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    return 0;
}