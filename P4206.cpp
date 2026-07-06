#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+100;
int n,m,a,b,dis[N][N],tot=0,head[N],vis[N],nxt[N][N];
double f[N][N];
struct node
{
    int to,next,from;
}e[N*2];
struct point
{
    int num,dis;
};
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
void bfs(int s)
{
    memset(vis,0,sizeof(vis));
    queue<point> q;
    q.push((point){s,0});
    vis[s]=true;
    while(!q.empty())
    {
        point t=q.front();q.pop();
        dis[s][t.num]=t.dis;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(vis[v])continue;
            vis[v]=true;
            q.push((point){v,t.dis+1});
        }
    }
}
double dfs(int x,int y)
{
    if(f[x][y]>0.0)return f[x][y];
    if(x==y)return 0.0;
    if(dis[x][y]<=2)return 1.0;
    double res=0.0,siz=1.0;
    for(int i=head[y];i;i=e[i].next)
    {
        int v=e[i].to;
        res+=dfs(nxt[nxt[x][y]][y],v);
        siz+=1.0;
    }
    res+=dfs(nxt[nxt[x][y]][y],y);
    f[x][y]=res/siz+1.0;
    return f[x][y];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>a>>b;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
        bfs(i);
    memset(nxt,127,sizeof(nxt));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=head[i],y=e[k].to;k;k=e[k].next,y=e[k].to)
                if(dis[i][j]==dis[j][y]+1)
                    nxt[i][j]=min(nxt[i][j],y);
    printf("%.3lf",dfs(a,b));
    return 0;
}