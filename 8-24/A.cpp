#include <bits/stdc++.h>
#define int long long
#define F(x) (qpow(x, P - 2))
#define endl "\n"
using namespace std;
const int N = 1e3 + 10, P = 1e9 + 7;
int n, m, x, a[N][N], f[N][N][2], c[N * 3], invc[N * 3];
int qpow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % P;
        y >>= 1;
        x = x * x % P;
    }
    return res;
}
int C(int x, int y)
{
    return c[x] * invc[x - y] % P * invc[y] % P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    c[0] = invc[0] = 1;
    for (int i = 1; i < 3 * N; i++)
        c[i] = c[i - 1] * i % P, invc[i] = invc[i - 1] * F(i) % P;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int k = 0; k <= 32; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int now = bool(a[i][j] & (1ll << k));
                // printf("a[i][j]=%lld,now=%lld\n",a[i][j],now);
                f[i][j][0] = (f[i - 1][j][now] + f[i][j - 1][now]) % P;
                f[i][j][1] = (f[i - 1][j][now ^ 1] + f[i][j - 1][now ^ 1]) % P;
                if (i == 1 && j == 1)
                    f[i][j][now] = (f[i][j][now] + 1) % P;
                // printf("f[%lld][%lld][%lld][0]=%lld\n",k,i,j,f[i][j][0]);
                // printf("f[%lld][%lld][%lld][1]=%lld\n",k,i,j,f[i][j][1]);
            }
        }
        ans = (ans + (1ll << k) * f[n][m][1] % P) % P;
    }
    ans = ans + ((qpow(2, n + m - 2) - C(n + m - 2, n - 1)) % P + P) % P * x % P;
    ans = ans * F(qpow(2, n + m - 2)) % P;
    cout << ans << endl;
    return 0;
}