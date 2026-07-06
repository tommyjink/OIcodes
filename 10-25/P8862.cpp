
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, INF = 1ll << 60;
int mn[N], lz[N], a[N], op[N], l[N], r[N], x[N], ans[N];
void rd(int &x)
{
    char c = getchar();
    x = 0;
    int f = 1;
    while (!isdigit(c))
        f = c == '-' ? -1 : 1, c = getchar();
    while (isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    x *= f;
}
void wt(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    char c[20];
    int t = 0;
    if (!x)
        putchar('0');
    while (x)
        c[t++] = x % 10 ^ 48, x /= 10;
    while (t--)
        putchar(c[t]);
    putchar(' ');
}
void ad(int p, int v)
{
    mn[p] += v;
    lz[p] += v;
}
void pd(int p)
{
    ad(p * 2, lz[p]);
    ad(p * 2 + 1, lz[p]);
    lz[p] = 0;
}
void bd(int p, int L, int R)
{
    if (L == R)
    {
        mn[p] = a[L];
        return;
    }
    int m = L + R >> 1;
    bd(p * 2, L, m);
    bd(p * 2 + 1, m + 1, R);
    mn[p] = min(mn[p * 2], mn[p * 2 + 1]);
}
void add(int p, int L, int R, int l, int r, int v)
{
    if (l <= L && R <= r)
    {
        ad(p, v);
        return;
    }
    pd(p);
    int m = L + R >> 1;
    if (l <= m)
        add(p * 2, L, m, l, r, v);
    if (r > m)
        add(p * 2 + 1, m + 1, R, l, r, v);
    mn[p] = min(mn[p * 2], mn[p * 2 + 1]);
}
int qry(int p, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
        return mn[p];
    pd(p);
    int m = L + R >> 1, res = INF;
    if (l <= m)
        res = min(res, qry(p * 2, L, m, l, r));
    if (r > m)
        res = min(res, qry(p * 2 + 1, m + 1, R, l, r));
    return res;
}
void sol()
{
    int n, q, t = 0;
    rd(n), rd(q);
    memset(lz, 0, sizeof lz);
    for (int i = 1; i <= n; i++)
        rd(a[i]);
    for (int i = 1; i <= q; i++)
    {
        rd(op[i]), rd(l[i]), rd(r[i]);
        if (op[i] == 1)
            rd(x[i]);
    }
    for (int i = 1; i <= n; i++)
        rd(a[i]);
    bd(1, 1, n);
    for (int i = q; i; i--)
    {
        if (op[i] == 1)
            add(1, 1, n, l[i], r[i], -x[i]);
        else
            ans[++t] = qry(1, 1, n, l[i], r[i]);
    }
    for (int i = t; i; i--)
        wt(ans[i]);
    puts("");
}
signed main()
{
    int T;
    rd(T);
    while (T--)
        sol();
    return 0;
}
