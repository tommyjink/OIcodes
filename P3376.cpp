#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205,M=5005,INF=1e16;
int n,m,s,t,dis[N],now[N];
int tot=1,head[N];
struct node
{
    int to,next,val;
}e[M*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
queue<int> q;
bool bfs()
{
    for(int i=1;i<=n;i++)dis[i]=INF,now[i]=head[i];
    dis[s]=0,q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].val&&dis[v]==INF)dis[v]=dis[x]+1,q.push(v);
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,0);
    }
    int ans=0;
    while(bfs())ans+=dfs(s,INF);
    cout<<ans<<endl;
    return 0;
}