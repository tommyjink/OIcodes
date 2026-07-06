//version 2.0
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2e5+100,M=N*40;
int n,m,a[N],b[N],c[N],done[M];
long long dis[M];
int head[M],tot=0,tt=0,S,T;
vector<int> in[N];
map<int,int> num[N];
struct node
{
    int from,to,next,val;
}e[M*2];
struct point
{
    int num,dis;
};
bool operator <(point x,point y)
{
    return x.dis>y.dis;
}
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
priority_queue<point> q;
void dijkstra()
{
    q.push((point){S,0});
    memset(dis,127,sizeof(dis));
    dis[S]=0;
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
    S=++tt,T=++tt;
    num[1][0]=S;
    in[1].push_back(0);
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]>b[i])swap(a[i],b[i]);
        if(!num[a[i]].count(c[i]))
            num[a[i]][c[i]]=++tt,in[a[i]].push_back(c[i]);
        if(!num[b[i]].count(c[i]))
            num[b[i]][c[i]]=++tt,in[b[i]].push_back(c[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<(int)in[a[i]].size();j++)
            add(num[a[i]][in[a[i]][j]],num[b[i]][c[i]],abs(in[a[i]][j]-c[i]));
        for(int j=0;j<(int)in[b[i]].size();j++)
            add(num[b[i]][in[b[i]][j]],num[a[i]][c[i]],abs(in[b[i]][j]-c[i]));
    }
    for(int i=0;i<(int)in[n].size();i++)
        add(num[n][in[n][i]],T,0);
    dijkstra();
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<(int)in[i].size();j++)
    //     {
    //         printf("dis[%lld from val %lld]=%lld\n",i,in[i][j],dis[num[i][in[i][j]]]);
    //     }
    // }
    cout<<dis[T];
    return 0;
}