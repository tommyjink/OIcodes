// Sakura
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 30, M = 1e4, INF = 1e9;
const int dx[] = {1, 0}, dy[] = {0, 1};
int n, m, k, v, a[N][N], px[N * N], ans = 0;
int sx[N * N], fans[N * N],tans[N*N];
bool com(int *x, int *y)
{
    for (int i = 1; i <= n + m - 1; i++)
        if (x[i] != y[i])
            return x[i] < y[i];
    return 0;
}
void sav()
{
    for (int j = 0; j < n + m - 1; j++)
    {
        for (int i = 1; i <= n + m - 1; i++)
            sx[i] = tans[(i + j - 1) % (n + m - 1) + 1];
        if (com(sx, fans))
            for (int i = 1; i <= n + m - 1; i++)
                fans[i] = sx[i];
    }
}
void dfs(int x, int y, int val)
{
    val += a[x][y] / k;
    val -= val / v;
    px[x + y - 1] = a[x][y];
    if (x == n && y == m)
    {
        if (ans < val)
        {
            for(int i=1;i<=n+m-1;i++)
                tans[i]=px[i];
            ans = val;
        }
        // else if (ans == val&&com(px,tans))
        //     for(int i=1;i<=n+m-1;i++)
        //         tans[i]=px[i];
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m)
            continue;
        dfs(xx, yy, val);
    }
}

signed main()
{
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fans[1] = INF;
    cin >> n >> m >> k >> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dfs(1, 1, 0);
    // cout<<ans<<endl;
    sav();
    for (int i = 1; i <= n + m - 1; i++)
        cout << fans[i] << " ";
    // cout << endl;
    return 0;
}