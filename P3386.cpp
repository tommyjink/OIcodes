#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,n1,n2,m,s,t,dis[N];
int tot=1,head[N],now[N];
struct node
{
    int to,next,val;
}e[N*4];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};head[x]=tot;
    e[++tot]=(node){x,head[y],0};head[y]=tot;
}
queue<int> q;
bool bfs()
{
    for(int i=1;i<=n;i++)
        dis[i]=INF,now[i]=head[i];
    dis[s]=0;q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dis[v]==INF&&e[i].val)dis[v]=dis[x]+1,q.push(v);
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
        now[x]=i;
        int v=e[i].to;
        if(!e[i].val||dis[v]!=dis[x]+1)continue;
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
    cin>>n1>>n2>>m;
    s=n1+n2+1,t=s+1;
    n=t;
    for(int i=1;i<=n1;i++)add(s,i,1);
    for(int i=1;i<=n2;i++)add(i+n1,t,1);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        y+=n1;
        add(x,y,1);
    }
    cout<<maxflow()<<endl;
    return 0;
}