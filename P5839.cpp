#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,M=30,INF=1e16;
int n,m,k,dis[M][M],w[N][M],a[N];
int f[N][M],g[N][M],mn[N];
string s;
int cal(int l,int r,int c)
{
    return w[r][c]-w[l-1][c];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)a[i]=s[i]-'a'+1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            cin>>dis[i][j];
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            w[i][j]=w[i-1][j]+dis[a[i]][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=g[i][j]=INF;
    for(int i=1;i<=n;i++)mn[i]=INF;
    for(int i=1;i<=n;i++)
    {
        for(int c=1;c<=m;c++)
        {
            if(i>=k)f[i][c]=min(mn[i-k],g[i-k][c])+cal(i-k+1,i,c);
            g[i][c]=min(g[i-1][c],mn[i-1])+cal(i,i,c);
            mn[i]=min(mn[i],f[i][c]);
        }
    }
    int ans=INF;
    for(int i=1;i<=m;i++)
        ans=min(ans,f[n][i]);
    cout<<ans<<endl;
    return 0;
}