#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20;
int n,m,f[N][N],in[N],ans=1e18,vis[N];
int sum=0,tot=0,v[N],fa[N],sx[3000],sy[3000];
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    return (fa[x]=getfa(fa[x]));
}
void dfs(int pos,int k,int now)
{
    if(now>ans)return;
    if(k<<1==tot)
    {
        ans=min(ans,now);
        return;
    }
    while(vis[pos])pos++;
    vis[pos]=true;
    for(int i=pos+1;i<=tot;i++)
    {
        if(vis[i])continue;
        vis[i]=true;
        dfs(pos+1,k+1,now+f[v[pos]][v[i]]);
        vis[i]=false;
    }
    vis[pos]=false;
            
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)f[i][j]=0;
            else f[i][j]=1e15;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        sx[i]=x,sy[i]=y;
        int fx=getfa(x);
        int fy=getfa(y);
        if(fx!=fy)fa[fx]=fy;
        sum+=z;
        in[x]++,in[y]++;
        f[x][y]=f[y][x]=min(f[x][y],z);
    }
    for(int i=1;i<=m;i++)
    {
        if(getfa(sx[i])!=getfa(1)||getfa(sy[i])!=getfa(1))
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
        if(in[i]&1)v[++tot]=i;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    dfs(1,0,0);
    cout<<ans+sum<<endl;
    return 0;
}