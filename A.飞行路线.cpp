#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e6+100;
int n,m,k,s,t;
int head[N],tot=0,dis[N],done[N];
struct node
{
    int from,to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
struct point
{
    int num,dis;
};
bool operator <(point x,point y)
{
    return x.dis>y.dis;
}
priority_queue<point> q;
void dijkstra()
{
    memset(dis,127,sizeof(dis));
    q.push((point){s,0});
    dis[s]=0;
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
    cin>>n>>m>>k>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
        for(int j=1;j<=k;j++)
        {
            add(x+j*n,y+j*n,z);
            add(y+j*n,x+j*n,z);
            add(x+(j-1)*n,y+j*n,0);
            add(y+(j-1)*n,x+j*n,0);
        }
    }
    dijkstra();
    int ans=1e10;
    for(int i=0;i<=k;i++)
        ans=min(ans,dis[t+i*n]);
    cout<<ans<<endl;
    return 0;
}