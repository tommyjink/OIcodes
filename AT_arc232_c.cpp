#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=405,INF=1e16;
int n,a[N],b[N],f[N][N],s,t,dis[N],in[N];
int c[N],cnt=0,tot=1,head[N],now[N];
int get(int x)
{
    return lower_bound(c+1,c+1+cnt,x)-c;
}
struct node
{
    int to,next,w,c;
}e[N*N*10];
void add(int x,int y,int w,int c)
{
    e[++tot]=(node){y,head[x],w,c};
    head[x]=tot;
    e[++tot]=(node){x,head[y],0,-c};
    head[y]=tot;
}
void clear()
{
    for(int i=0;i<=tot;i++)
        head[i]=now[i]=in[i]=0;
    tot=1;
}
bool spfa()
{
    for(int i=1;i<=t;i++)
        dis[i]=INF,now[i]=head[i];
    queue<int> q;
    q.push(s);
    dis[s]=0;
    in[s]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        in[x]=0;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].w&&dis[v]>dis[x]+e[i].c)
            {
                dis[v]=dis[x]+e[i].c;
                if(!in[v])q.push(v);
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
            e[i].w-=k;
            e[i^1].w+=k;
            sum-=k;
            res+=k;
        }
    }
    in[x]=0;
    return res;
}
int mincost()
{
    int maxflow=0,res=0;
    while(spfa())
    {
        int k=dfs(s,INF);
        maxflow+=k;
        res+=k*dis[t];
    }
    if(maxflow!=n)return -1;
    return res;
}
void solve()
{
    cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],c[++cnt]=a[i],c[++cnt]=-a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i],c[++cnt]=b[i],c[++cnt]=-b[i];
    sort(c+1,c+1+cnt);
    cnt=unique(c+1,c+1+cnt)-c-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=get(a[i]);
        b[i]=get(b[i]);
    }
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            if(i!=j)f[i][j]=INF;
    for(int i=2;i<=cnt;i++)
        f[i-1][i]=c[i]-c[i-1];
    for(int i=1;i<=cnt;i++)
        f[i][get(-c[i])]=min(f[i][get(-c[i])],1ll);
    for(int k=1;k<=cnt;k++)
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=cnt;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            add(i,j+n,1,f[a[i]][b[j]]);
    s=cnt+1,t=cnt+2;
    for(int i=1;i<=n;i++)
        add(s,a[i],1,0),
        add(b[i]+n,t,1,0);
    cout<<mincost()<<endl;
    clear();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}