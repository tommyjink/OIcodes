#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,k,s,t,m,head[N],tot=1;
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
    cin>>n>>m;
    s=n+1,t=n+2;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x>=0)add(s,i,x),sum+=x;
        else add(i,t,-x);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y,INF);
    }
    cout<<sum-maxflow()<<endl;
    return 0;
}