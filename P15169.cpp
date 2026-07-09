#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205,INF=1e10;
int n,m,k,c[N],d[N][N][2],f[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=2*n;i++)
        for(int j=1;j<=2*n;j++)
            if(i!=j)f[i][j]=INF;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        if(c[x]==c[y])f[x][y]=f[x+n][y+n]=f[y][x]=f[y+n][x+n]=1;
        else f[x][y+n]=f[x+n][y]=f[y][x+n]=f[y+n][x]=1;
    }
    for(int k=1;k<=2*n;k++)
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j][0]=f[i][j],
            d[i][j][1]=f[i][j+n];
    int ans=0;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            for(int h=0;h<=k;h++)
                ans=max(ans,min(d[x][y][0]+h,d[x][y][1]+k-h));
    cout<<ans<<endl;
    return 0;
}