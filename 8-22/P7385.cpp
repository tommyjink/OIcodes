#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P = 1e9 + 7, N = 1e6 + 100;
int n, a, b, m, ex[N], f[N], g[N];
int qpow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % P;
        x = x * x % P;
        y >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b >> m;
    a = a * qpow(100, P - 2) % P;
    b = b * qpow(100, P - 2) % P;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ex[x] = y;
    }
    g[0] = 2;
    for (int i = 1; i <= n; i++)
    {
        g[i] = (2 * b * g[i - 1] % P + a * 2 % P) * qpow(a + b, P - 2) % P;
        f[i] = (f[i - 1] + qpow(a + b, i - 1) * (a + b * (g[i - 1] + ex[i]) % P) % P) % P;
    }
    cout << f[n];
    return 0;
}