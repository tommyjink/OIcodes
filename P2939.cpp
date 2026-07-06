#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+100,M=5e6;
int n,m,k,dis[N],done[N];
int head[N],tot=0;
struct node
{
    int from,to,next,val;
}e[M];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
struct point
{
    int num,dis;
};
bool operator<(point x,point y)
{
    return x.dis>y.dis;
}
priority_queue<point> q;
void dijkstra(int s)
{
    memset(dis,127,sizeof(dis));
    dis[s]=0;
    q.push((point){s,0});
    while(!q.empty())
    {
        point t=q.top();q.pop();
        if(done[t.num])continue;
        // cout<<t.num<<endl;
        done[t.num]=true;
        // cout<<head[t.num]<<"||"<<endl;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            // cout<<v<<"!"<<endl;
            if(done[v])continue;
            if(t.dis+e[i].val<dis[v])
            {
                dis[v]=t.dis+e[i].val;
                q.push((point){v,dis[v]});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("P2939_2.in","r",stdin);
    cin>>n>>m>>k;
    // cout<<n<<endl;
    for(int i=1;i<=m;i++)
    {
        // cout<<"1"<<endl;
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
        for(int j=1;j<=k;j++)
        {
            int xx=x+j*n,yy=y+j*n;
            add(xx,yy,z);
            add(yy,xx,z);
            add(xx-n,yy,0);
            add(yy-n,xx,0);
            // add(xx-n,xx,0);
            // add(yy-n,yy,0);
        }
    }
    // cout<<tot<<endl;
    dijkstra(1);
    // cout<<dis[2];
    int ans=1e10;
    for(int i=1;i<=k;i++)
        ans=min(ans,dis[n+i*n]);
    cout<<ans;
    return 0;
}