#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int tot=1,head[N],dis[N],now[N];
int n,s,t,in[N];
struct node
{
    int to,next,w,c;
}e[N*2];
void add(int x,int y,int w,int c)
{
    e[++tot]=(node){y,head[x],w,c},head[x]=tot;
    e[++tot]=(node){x,head[y],0,-c},head[y]=tot;
}
queue<int> q;
bool min_spfa()
{
    for(int i=1;i<=t;i++)
        dis[i]=INF,now[i]=head[i];
    q.push(s),dis[s]=0,in[s]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        in[x]=0;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].w&&dis[x]+e[i].c<dis[v])
            {
                dis[v]=dis[x]+e[i].c;
                if(!in[v])q.push(v),in[v]=1;
            }
        }
    }
    return dis[t]!=INF;
}
bool max_spfa()
{
    for(int i=1;i<=t;i++)
        dis[i]=-INF,now[i]=head[i],in[i]=0;
    q.push(s),dis[s]=0,in[s]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        in[x]=0;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].w&&dis[x]+e[i].c>dis[v])
            {
                dis[v]=dis[x]+e[i].c;
                if(!in[v])q.push(v),in[v]=1;
            }
        }
    }
    return dis[t]!=-INF;
}
int dfs(int x,int sum)
{
    if(x==t)return sum;
    in[x]=1;int res=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!in[v]&&dis[x]+e[i].c==dis[v]&&e[i].w)
        {
            int k=dfs(v,min(sum,e[i].w));
            e[i].w-=k,e[i^1].w+=k;
            sum-=k,res+=k;
        }
    }
    in[x]=0;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    s=2*n+1,t=s+1;
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=n;j++)
        {
            int c;
            cin>>c;
            add(i,j+n,INF,c);
        }
    }
    for(int i=1;i<=n;i++)
        add(s,i,1,0);
    for(int i=n+1;i<=2*n;i++)
        add(i,t,1,0);
    int mincost=0,maxcost=0;
    while(min_spfa())mincost+=dis[t]*dfs(s,INF);
    for(int i=2;i<=tot;i+=2)e[i].w+=e[i^1].w,e[i^1].w=0;
    while(max_spfa())maxcost+=dis[t]*dfs(s,INF);
    cout<<mincost<<endl<<maxcost<<endl;
    return 0;
}