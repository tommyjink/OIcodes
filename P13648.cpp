#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005,INF=1e16;
int n,s,t,head[N*2],tot=1,f[N][N];
int dis[N*2],now[N*2],a[N*2][3];
struct node
{
    int to,next,val;
}e[N*N*4];
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
    cin>>n;
    s=2*n+1,t=s+1;
    for(int i=1;i<=n;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][1]<a[j][1]&&
            max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1]))
            <=max(a[i][2],a[j][2]))f[i][j]=true;
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(f[i][k]&&f[k][j])f[i][j]=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j])add(i,j+n,1);
    for(int i=1;i<=n;i++)add(s,i,1);
    for(int i=n+1;i<=2*n;i++)add(i,t,1);
    int res=n-maxflow()+1;
    if(res>n)cout<<-1<<endl;
    else cout<<res<<endl;
    return 0;
}