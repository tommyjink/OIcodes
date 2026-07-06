#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6,M=500;
int n,m,k,q,b[10],tag[M],st[10],ed[10],ans=0,vl[N];
int head[M],tot=0,dis[M][M],done[M],vis[10];
struct node
{
    int from,to,next,val,num;
}e[N*2];
struct point
{
    int num,dis;
};
bool operator <(point x,point y)
{
    return x.dis>y.dis;
}
void add(int x,int y,int z,int num)
{
    e[++tot]=(node){x,y,head[x],z,num};
    head[x]=tot;
}
void dijkstra(int s)
{
    priority_queue<point> q;
    q.push((point){s,0});
    dis[s][s]=0;
    while(!q.empty())
    {
        point t=q.top();q.pop();
        int x=t.num;
        if(done[x])continue;
        done[t.num]=true;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to,val=e[i].val;
            if(done[v])continue;
            if(t.dis+val<dis[s][v])
                dis[s][v]=t.dis+val,
                q.push((point){v,dis[s][v]});
        }
    }
}
void dfs(int x,int cnt,int num)
{
    if(cnt>k)
    {
        ans=min(ans,num+dis[x][n]);
        return;
    }
    else
    {
        for(int i=1;i<=k;i++)
        {
            if(vis[i])continue;
            vis[i]=true;
            dfs(ed[i],cnt+1,num+dis[x][st[i]]+vl[i]);
            dfs(st[i],cnt+1,num+dis[x][ed[i]]+vl[i]);
            vis[i]=false;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dis,127,sizeof(dis));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z,i);
        add(y,x,z,i);
    }
    for(int i=1;i<=n;i++)
    {
        memset(done,0,sizeof(done));
        dijkstra(i);
        // for(int j=1;j<=n;j++)
        //     printf("dis[%lld][%lld]=%lld\n",i,j,dis[i][j]);
    }
    cin>>q;
    while(q--)
    {
        cin>>k;ans=1e10;
        for(int i=1;i<=k;i++)
        {
            cin>>b[i];
            st[i]=e[b[i]*2].from;
            ed[i]=e[b[i]*2].to;
            vl[i]=e[b[i]*2].val;
        }
        dfs(1,1,0);
        cout<<ans<<endl;
    }
    return 0;
}