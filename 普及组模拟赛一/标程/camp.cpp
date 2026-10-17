#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3010,INF=4e18;
int n,k,a[N],f[N][N],siz[N];
vector<int> e[N];
void dfs(int x,int fa)
{
    siz[x]=1;f[x][1]=a[x];
    for(int y:e[x])
    {
        if(y==fa)continue;dfs(y,x);
        for(int i=min(siz[x],k);i>=1;i--)
            for(int j=1;j<=min(siz[y],k-i);j++)
                if(f[x][i]>-INF&&f[y][j]>-INF)
                    f[x][i+j]=max(f[x][i+j],f[x][i]+f[y][j]);
        siz[x]+=siz[y];
    }
}
signed main()
{
    freopen("camp.in","r",stdin);freopen("camp.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,x,y;i<n;i++)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
    for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)f[i][j]=-INF;
    dfs(1,0);cout<<f[1][k]<<endl;
    return 0;
}
