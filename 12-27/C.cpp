#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505;
const int MOD=998244353;
int n,m;
int head[N],tot=0;
int dep[N],lim[N];
int f[N][N],tmp[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs1(int u,int fa,int d)
{
    dep[u]=d;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa) dfs1(v,u,d+1);
    }
}
void dp(int u,int fa)
{
    f[u][dep[lim[u]]]=1;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dp(v,u);
        for(int j=0;j<=n;j++) tmp[j]=0;
        for(int j=0;j<=n;j++)
        {
            if(!f[u][j]) continue;
            for(int k=0;k<=n;k++)
            {
                if(!f[v][k]) continue;
                if(k<=dep[u])
                {
                    tmp[j]=(tmp[j]+f[u][j]*f[v][k])%MOD;
                }
                int mx=max(j,k);
                tmp[mx]=(tmp[mx]+f[u][j]*f[v][k])%MOD;
            }
        }
        for(int j=0;j<=n;j++) f[u][j]=tmp[j];
    }
    for(int j=dep[u];j<=n;j++) f[u][j]=0;
}
void solve1()
{
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs1(1,0,1);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(dep[u]>dep[lim[v]]) lim[v]=u;
    }
    dp(1,0);
    cout<<f[1][0]<<endl;
    return 0;
}