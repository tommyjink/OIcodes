#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,s,t,head[N],tot=1;
int dis[N],now[N],in[N];
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
bool spfa()
{
    for(int i=1;i<=n;i++)
        dis[i]=INF,now[i]=head[i];
    q.push(s),dis[s]=0,in[s]=1;
    while(!q.empty())
    {
        int x=q.front();in[x]=0;q.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].w&&dis[x]+e[i].c<dis[v])
            {
                dis[v]=dis[x]+e[i].c;
                if(!in[v])in[v]=1,q.push(v);
            }
        }
    }
    return dis[t]!=INF;
}
int dfs(int x,int sum)
{
    int res=0;
    if(x==t)return sum;
    in[x]=1;
    for(int i=now[x];i&&sum;i=e[i].next)
    {
        now[x]=i;
        int v=e[i].to;
        if(e[i].w&&dis[v]==dis[x]+e[i].c&&!in[v])
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
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int x,y,w,c;
        cin>>x>>y>>w>>c;
        add(x,y,w,c);
    }
    int maxflow=0,mincost=0;
    while(spfa())
    {
        int flow=dfs(s,INF);
        // cout<<flow<<endl;
        maxflow+=flow;
        mincost+=flow*dis[t];
    }
    cout<<maxflow<<" "<<mincost<<endl;
    return 0;
}