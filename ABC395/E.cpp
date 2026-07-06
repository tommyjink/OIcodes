#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+100;
int n,m,X,dis[N*2],done[N*2];
int head[N*2],tot=0;
struct node
{
    int from,to,next,val;
}e[N*10];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
struct point
{
    int dis,num;
};
bool operator <(point x,point y)
{
    return x.dis>y.dis;
}
priority_queue<point> q;
void dijkstra()
{
    memset(dis,127,sizeof(dis));
    q.push((point){0,1});
    dis[1]=0;
    while(!q.empty())
    {
        point t=q.top();q.pop();
        if(done[t.num])continue;
        // printf("vis:%lld dis:%lld\n",t.num,t.dis);
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(t.dis+e[i].val<dis[v])
            {
                dis[v]=t.dis+e[i].val;
                q.push((point){dis[v],v});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>X;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y,1);
        add(y+n,x+n,1);
        add(y,y+n,X);
        add(x,x+n,X);
        add(x+n,x,X);
        add(y+n,y,X);
    }
    dijkstra();
    // for(int i=1;i<=2*n;i++)
    //     printf("dis[%lld]=%lld\n",i,dis[i]);
    cout<<min(dis[n],dis[2*n]);
    return 0;
}