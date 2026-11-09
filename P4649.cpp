#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1100,M=5100;
int n,m,cnt=0,lg[N];
int head[N],tot=0;
int dep[N],f[N][21];
int dp[N][M],h[N];
int L[N],R[N],num=0;
int a[N],b[N][N],p[N];
struct node
{
    int to,next;
}e[N*2];
struct xyz
{
    int x,y,z;
}g[M],r[M];
vector<int> d[N],son[N]; 
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    L[x]=++num;
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=20;i++)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
    R[x]=num;
}
bool in(int x,int y)
{
    return (L[x]>=L[y]&&L[x]<=R[y]);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int dis(int x,int y)
{
    int o=lca(x,y);
    return dep[x]+dep[y]-2*dep[o];
}
int jump(int x,int d)
{
    for(int i=20;i>=0;i--)
        if(dep[f[x][i]]>=d)
            x=f[x][i];
    return x;
}
void dfs1(int x)
{
    int B=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==f[x][0])continue;
        son[x].push_back(v);
        dfs1(v);
        B+=dp[v][0];
    }
    int k=son[x].size();
    for(int i=0;i<k;i++)p[son[x][i]]=i;
    for(int i=0;i<k;i++)
    {
        a[i]=0;
        for(int j=0;j<k;j++)
            b[i][j]=0;
    }
    for(int i=1;i<=cnt;i++)
    {
        int y=r[i].x,z=r[i].y,val=r[i].z;
        if(!in(y,x)||!in(z,x))continue;
        if(y==x)
        {
            int zz=jump(z,dep[x]+1);
            a[p[zz]]=max(a[p[zz]],dp[zz][i]-dp[zz][0]+val);
        }
        else
        {
            int yy=jump(y,dep[x]+1);
            int zz=jump(z,dep[x]+1);
            b[p[yy]][p[zz]]=max(b[p[yy]][p[zz]],dp[yy][i]+dp[zz][i]-dp[yy][0]-dp[zz][0]+val);
            b[p[zz]][p[yy]]=max(b[p[zz]][p[yy]],dp[yy][i]+dp[zz][i]-dp[yy][0]-dp[zz][0]+val);
        }
    }
    h[0]=0;
    for(int s=1;s<(1<<k);s++)
    {
        int i=lg[lowbit(s)];
        h[s]=h[s^(1<<i)]+max(0,a[i]);
        for(int j=0;j<k;j++)
        {
            if(j!=i&&(s&(1<<j)))
            {
                h[s]=max(h[s],h[s^(1<<i)^(1<<j)]+b[i][j]);
            }
        }
    }
    dp[x][0]=B+h[(1<<k)-1];
    for(int i=1;i<=cnt;i++)
    {
        int y=r[i].x,z=r[i].y,val=r[i].z;
        if(in(y,x)&&!in(z,x))swap(y,z);
        if(!in(y,x)&&in(z,x))
        {
            if(z==x)dp[x][i]=B+h[(1<<k)-1];
            else
            {
                int zz=jump(z,dep[x]+1);
                dp[x][i]=B-dp[zz][0]+dp[zz][i]+h[((1<<k)-1)^(1<<p[zz])];
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>g[i].x>>g[i].y>>g[i].z;
        if(g[i].z==0)add(g[i].x,g[i].y),add(g[i].y,g[i].x);
    }
    dfs(1,0);
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum+=g[i].z;
        if(g[i].z&&dis(g[i].x,g[i].y)%2==0)
        {
            r[++cnt]=g[i];
            if(dep[r[cnt].x]>dep[r[cnt].y])
                swap(r[cnt].x,r[cnt].y);
        }
    }
    dfs1(1);
    cout<<sum-dp[1][0]<<endl;
    return 0;
}