#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int tot=1,head[N],n,m1,m2;
int s,t;
int dis[N],now[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z},head[x]=tot;
    e[++tot]=(node){x,head[y],0},head[y]=tot;
}
queue<int> q;
bool bfs()
{
    for(int i=1;i<=t;i++)
        dis[i]=INF,now[i]=head[i];
    dis[s]=0;q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dis[v]==INF&&e[i].val)q.push(v),dis[v]=dis[x]+1;
        }
    }
    return dis[t]!=INF;
}
int dfs(int x,int sum)
{
    int res=0;
    if(x==t)return sum;
    for(int i=now[x];i;i=e[i].next)
    {
        int v=e[i].to;now[x]=i;
        if(dis[v]!=dis[x]+1||!e[i].val)continue;
        int k=dfs(v,min(sum,e[i].val));
        e[i].val-=k,e[i^1].val+=k;
        sum-=k,res+=k;
    }
    return res;
}
int maxflow()
{
    int res=0;
    while(bfs())res+=dfs(s,INF);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m1>>m2;
    s=2*n+m1+m2+1;
    t=s+1;
    for(int i=1;i<=n;i++)add(i,i+n,1);
    for(int i=1;i<=m1;i++)add(s,i+2*n,1);
    for(int i=1;i<=m2;i++)add(i+2*n+m1,t,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m1;j++)
        {
            int x;cin>>x;
            if(x)add(j+2*n,i,1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m2;j++)
        {
            int x;cin>>x;
            if(x)add(i+n,j+2*n+m1,1);
        }
    }
    cout<<maxflow()<<endl;
    return 0;
}