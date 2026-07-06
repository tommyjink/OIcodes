#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int head[N],tot=0,dis[N],f[10][10];
int done[N],n,m,pos[10];
struct node
{
    int from,to,next,val;
}e[N*2];
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
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
priority_queue<Point> q;
void dijkstra(int s)
{
    memset(dis,127,sizeof(dis));
    memset(done,0,sizeof(done));
    while(!q.empty())q.pop();
    dis[s]=0;
    q.push((Point){s,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(dis[t.num]+e[i].val<dis[v])
            {
                dis[v]=dis[t.num]+e[i].val;
                q.push((Point){v,dis[v]});
            }
        }
    }
}
signed main()
{
    freopen("newyear.in","r",stdin);
    freopen("newyear.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    pos[1]=1;
    for(int i=2;i<=6;i++)
        cin>>pos[i];
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=6;i++)
    {
        dijkstra(pos[i]);
        for(int j=i+1;j<=6;j++)
        {
            f[j][i]=f[i][j]=dis[pos[j]];
            // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
        }
    }
    int ans=1e18;
    for(int A=2;A<=6;A++)
        for(int B=2;B<=6;B++)
            if(A!=B)for(int C=2;C<=6;C++)
                if(A!=C&&B!=C)for(int D=2;D<=6;D++)
                    if(A!=D&&B!=D&&C!=D)for(int E=2;E<=6;E++)
                        if(A!=E&&B!=E&&C!=E&&D!=E)
                        {
                            ans=min(ans,f[1][A]+f[A][B]+f[B][C]+f[C][D]+f[D][E]);
                            // cout<<A<<","<<B<<","<<C<<","<<D<<","<<E<<":"<<f[1][A]+f[A][B]+f[B][C]+f[C][D]+f[D][E]<<endl;
                        }
    cout<<ans<<endl;

    return 0;
}
/*
【样例输入】
6 6
2 3 4 5 6
1 2 8
2 3 3
3 4 4
4 5 5
5 6 2
1 6 7
【样例输出】
21
*/