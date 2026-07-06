

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2007, P = 1e9 + 7;
int n, a[N], f[N][N], g[N], h[N], ans;
int rv[N][N], cv[N][N];
void rinit(int x)
{
    for (int i = 1; i <= n + 1; i++)
        rv[x][i] = 0;
}
void cinit(int x)
{
    for (int i = 1; i <= n + 1; i++)
        cv[x][i] = 0;
}
void radd(int x, int y, int k)
{
    for (; y <= n + 1; y += y & -y)
        rv[x][y] = (rv[x][y] + k >= P ? rv[x][y] + k - P : rv[x][y] + k);
}
void cadd(int x, int y, int k)
{
    for (; y <= n + 1; y += y & -y)
        cv[x][y] = (cv[x][y] + k >= P ? cv[x][y] + k - P : cv[x][y] + k);
}
int rask(int x, int y)
{
    int s = 0;
    for (; y; y -= y & -y)
        s = (s + rv[x][y] >= P ? s + rv[x][y] - P : s + rv[x][y]);
    return s;
}
int cask(int x, int y)
{
    int s = 0;
    for (; y; y -= y & -y)
        s = (s + cv[x][y] >= P ? s + cv[x][y] - P : s + cv[x][y]);
    return s;
}
void up(int &x, int y) { x = (x + y >= P ? x + y - P : x + y); }
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i <= n; i++)
            rinit(i), cinit(i);
        radd(0, 1, 1), cadd(0, 1, 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                g[j] = cask(j, a[i] + 1);
                h[j] = a[i] < j ? rask(j, a[i] + 1) : 0;
            }
            for (int j = 0; j <= n; j++)
            {
                radd(a[i], j + 1, g[j]);
                radd(j, a[i] + 1, h[j]);
                cadd(j, a[i] + 1, g[j]);
                cadd(a[i], j + 1, h[j]);
                up(f[a[i]][j], g[j]);
                up(f[j][a[i]], h[j]);
            }
        }
        for (int i = 0; i <= n; i++)
            up(ans, cask(i, n + 1));
        cout << ans << "\n";
    }
    return 0;
}
