
#include <bits/stdc++.h>
#define int long long
#define N 40010
#define M 100010
using namespace std;
int n, m, r, a[N], b[N], f[N], g[N], ans;
struct E
{
    int u, v;
} e[M];
int rd()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + (c ^ 48), c = getchar();
    return x * f;
}
signed main()
{
    n = rd(), m = rd(), r = rd();
    for (int i = 1; i <= n; i++)
        a[i] = f[i] = rd(), ans = max(ans, a[i]);
    for (int i = 1; i <= m; i++)
        b[i] = g[i] = rd(), ans = max(ans, b[i]);
    for (int i = 1; i <= r; i++)
        e[i].u = rd(), e[i].v = rd();
    sort(e + 1, e + r + 1, [](E x, E y)
         { return x.u == y.u ? x.v < y.v : x.u < y.u; });
    for (int i = 1; i <= r; i++)
    {
        int t1 = f[e[i].u], t2 = g[e[i].v];
        f[e[i].u] = max(f[e[i].u], t2 + a[e[i].u]);
        g[e[i].v] = max(g[e[i].v], t1 + b[e[i].v]);
        ans = max(ans, max(f[e[i].u], g[e[i].v]));
    }
    printf("%lld\n", ans);
    return 0;
}
