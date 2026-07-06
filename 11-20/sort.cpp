#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10, P = 1e9 + 7;
int n, m, a[N], b[N], c[N], fac[N], inv_fac[N], cat[N]; 

struct node
{
    int lazy, l, r, val;
} t[N * 8], t1[N * 8], t2[N * 8];
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

void init_cat()
{
    fac[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % P;
    }
    inv_fac[N - 1] = qpow(fac[N - 1], P - 2);
    for (int i = N - 2; i >= 0; i--)
    {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % P;
    }
    cat[0] = 1;
    for (int k = 1; k <= 5e5; k++)
    { 
        int C = fac[2 * k] * inv_fac[k] % P;
        C = C * inv_fac[k] % P;
        int inv_k1 = qpow(k + 1, P - 2);
        cat[k] = C * inv_k1 % P;
    }
}
void pushdown(node *t, int k)
{
    t[k * 2].lazy += t[k].lazy;
    t[k * 2 + 1].lazy += t[k].lazy;
    t[k * 2].val += (t[k * 2].r - t[k * 2].l + 1) * t[k].lazy;
    t[k * 2 + 1].val += (t[k * 2 + 1].r - t[k * 2 + 1].l + 1) * t[k].lazy;
    t[k].lazy = 0;
}
void pushup(node *t, int k)
{
    t[k].val = (t[k * 2].val + t[k * 2 + 1].val);
}
void build(node *t, int *a, int k, int l, int r)
{
    t[k].l = l, t[k].r = r;
    t[k].lazy = 0;
    if (l == r)
    {
        t[k].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(t, a, k * 2, l, mid);
    build(t, a, k * 2 + 1, mid + 1, r);
    pushup(t, k);
}
void add(node *t, int k, int l, int r, int d)
{
    if (t[k].r < l || t[k].l > r)
        return;
    if (l <= t[k].l && t[k].r <= r)
    {
        t[k].lazy += d;
        t[k].val += d * (t[k].r - t[k].l + 1);
        return;
    }
    pushdown(t, k);
    add(t, k * 2, l, r, d);
    add(t, k * 2 + 1, l, r, d);
    pushup(t, k);
}
int query(node *t, int k, int l, int r)
{
    if (t[k].r < l || t[k].l > r)
        return 0;
    if (l <= t[k].l && t[k].r <= r)
        return t[k].val;
    pushdown(t, k);
    return query(t, k * 2, l, r) + query(t, k * 2 + 1, l, r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_cat();
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    for (int i = 1; i <= 2 * n; i++)
        if (i & 1)
            b[(i + 1) / 2] = a[i];
        else
            c[i / 2] = a[i];
    build(t, a, 1, 1, 2 * n);
    build(t1, b, 1, 1, n);
    build(t2, c, 1, 1, n);
    // for(int i=1;i<=n;i++)
    //     cout<<query(t1,1,i,i)<<" "<<query(t2,1,i,i)<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<" "<<c[i]<<endl;
    while (m--)
    {
        int op;
        cin >> op;
        if (op)
        {
            int x, y;
            cin >> x >> y;
            int res1 = query(t, 1, (x + y) / 2 + 1, y) - query(t, 1, x, (x + y) / 2);
            int res2 = abs(query(t1, 1, (x + 1) / 2, y / 2) - query(t2, 1, (x + 1) / 2, y / 2));
            int res3 = cat[(y - x + 1) / 2];
            cout << res1 << " " << res2 << " " << res3 << endl;
        }
        else
        {
            int x, y, z;
            cin >> x >> y >> z;
            add(t, 1, x, y, z);
            add(t1, 1, (x + 1) / 2, y / 2, z);
            add(t2, 1, (x + 1) / 2, y / 2, z);
        }
    }
    return 0;
}
/*



输入
3 3
1 2 3 4 5 6
1 1 6
0 1 6 10
1 1 6

输出
9 3 5
9 3 5



*/