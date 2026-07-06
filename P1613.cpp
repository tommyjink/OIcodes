#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 100;
int n, m, f[N][N][N], dis[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        f[0][x][y] = 1;
        dis[x][y] = 1;
    }
    for (int t = 0; t <= 64; t++)
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (f[t][i][k] && f[t][k][j])
                        f[t + 1][i][j] = true, dis[i][j] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    cout << dis[1][n] << endl;
    return 0;
}