#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 505,INF = 1e15;
int n, m, f[N][N], d[N][N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = d[i][j] = INF;
    for(int i=1;i<=n;i++)f[i][i]=0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        f[x][y] = f[y][x] = 1;
        d[x][y]=min(d[x][y],z);
        d[y][x]=min(d[y][x],z);
        
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    int ans = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][j] < INF)
                ans = min(ans, d[i][j]*(f[1][i]+f[n][j]+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(d[i][j]<INF)
                for(int k=1;k<=n;k++)
                    ans=min(ans,d[i][j]*(f[1][k]+f[n][k]+f[i][k]+1+1));
    cout<< ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}