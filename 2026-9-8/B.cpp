#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,M=1e6+10,K=4e5+10,L=18,INF=N;
int n,m,head[N],tot,dis[N],vis[N],ord[N],cnt;
int rt1[N],rt2[N],s1[N],s2[N],tt=1;
int f[K][L],dep[K],val[K];

struct node
{
    int to,next,w,id;
}e[M];

struct path
{
    int x,w,s;
};

void add(int x,int y,int w,int id)
{
    e[++tot]={y,head[x],w,id};
    head[x]=tot;
}

void dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii> >q;
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        int x=q.top().second;q.pop();
        if(vis[x])continue;
        vis[x]=1;
        ord[++cnt]=x;
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].w)
            {
                dis[y]=dis[x]+e[i].w;
                q.push({dis[y],y});
            }
        }
    }
}

int newnode(int x,int w)
{
    ++tt;
    dep[tt]=dep[x]+1;
    val[tt]=w;
    f[tt][0]=x;
    for(int i=1;i<L;i++)f[tt][i]=f[f[tt][i-1]][i-1];
    return tt;
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    int d=dep[x]-dep[y];
    for(int i=0;i<L;i++)
        if(d>>i&1)x=f[x][i];
    if(x==y)return x;
    for(int i=L-1;i>=0;i--)
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    return f[x][0];
}

int jump(int x,int d)
{
    for(int i=0;i<L;i++)
        if(d>>i&1)x=f[x][i];
    return x;
}

bool cmp(path a,path b)
{
    if(!b.x)return 1;
    if(a.x==b.x)return a.w<b.w;
    int z=lca(a.x,b.x);
    if(z!=a.x&&z!=b.x)
    {
        int x=jump(a.x,dep[a.x]-dep[z]-1);
        int y=jump(b.x,dep[b.x]-dep[z]-1);
        return val[x]<=val[y];
    }
    if(z==a.x)
    {
        int y=jump(b.x,dep[b.x]-dep[z]-1);
        if(a.w!=val[y])return a.w<=val[y];
        return 1;
    }
    int x=jump(a.x,dep[a.x]-dep[z]-1);
    if(val[x]!=b.w)return val[x]<=b.w;
    return 0;
}

void upd(path x,path &x1,path &x2)
{
    if(cmp(x,x1))
    {
        x2=x1;
        x1=x;
    }
    else if(cmp(x,x2))
        x2=x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        add(x,y,w,i);
        add(y,x,w,i);
    }
    dijkstra();
    rt1[1]=1;
    for(int i=2;i<=cnt;i++)
    {
        int x=ord[i];
        path x1={0,0,0},x2={0,0,0};
        for(int j=head[x];j;j=e[j].next)
        {
            int y=e[j].to;
            if(dis[y]+e[j].w!=dis[x])continue;
            path z={rt1[y],e[j].id,s1[y]+e[j].id};
            upd(z,x1,x2);
            if(rt2[y])
            {
                z={rt2[y],e[j].id,s2[y]+e[j].id};
                upd(z,x1,x2);
            }
        }
        rt1[x]=newnode(x1.x,x1.w);
        s1[x]=x1.s;
        if(x2.x)
        {
            rt2[x]=newnode(x2.x,x2.w);
            s2[x]=x2.s;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(rt2[i])cout<<s2[i]<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
    return 0;
}
