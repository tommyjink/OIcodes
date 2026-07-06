// https://codeforces.com/problemset/problem/19/D
// https://www.luogu.com.cn/problem/CF19D
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6;
int n, X[N], Y[N], ax, ay, nxt[N], lst[N];
string s[N];
struct node
{
    int x, y;
} a[N];
bool operator<(const node &x, const node &y)
{
    return x.x == y.x ? x.y < y.y : x.x < y.x;
}
struct Tree
{
    int l, r, val, maxval;
} t[N * 4];
void pushup(int k)
{
    t[k].val = t[k * 2].val + t[k * 2 + 1].val;
    t[k].maxval = max(t[k * 2].maxval, t[k * 2 + 1].maxval);
}
void build(int k, int l, int r)
{
    t[k].l = l, t[k].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
}
void add(int k, int x, int d)
{
    if (t[k].l > x || t[k].r < x)
        return;
    if (t[k].l == t[k].r)
    {
        t[k].maxval = d;
        t[k].val = 1;
        return;
    }
    add(k * 2, x, d);
    add(k * 2 + 1, x, d);
    pushup(k);
}
void rem(int k, int x)
{
    if (t[k].l > x || t[k].r < x)
        return;
    if (t[k].l == t[k].r)
    {
        t[k].maxval = t[k].val = 0;
        return;
    }
    rem(k * 2, x);
    rem(k * 2 + 1, x);
    pushup(k);
}
void query(int k, int l, int r, int now)
{
    if (t[k].l > r || t[k].r < l)
        return;
    if (t[k].maxval <= now)
        return;
    if (t[k].l == t[k].r)
    {
        ax = t[k].l;
        ay = t[k].maxval;
        return;
    }
    if (t[k * 2].val > 0 && t[k * 2].maxval > now)
        query(k * 2, l, r, now);
    if (!(ax && ay))
        query(k * 2 + 1, l, r, now);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    build(1, 1, n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> X[i] >> Y[i];
        a[i] = (node){X[i], Y[i]};
    }
    sort(a + 1, a + 1 + n);
    int tot = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] < a[tot] || a[tot] < a[i] || tot == 0)
            a[++tot] = a[i];
    for (int i = 1; i <= n; i++)
        X[i] = lower_bound(a + 1, a + 1 + tot, (node){X[i], Y[i]}) - a;
    for (int i = tot; i >= 1; i--)
        if (a[i].x == a[i + 1].x)
            nxt[i] = nxt[i + 1];
        else
            nxt[i] = i + 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == "add")
        {
            add(1, X[i], Y[i]);
        }
        if (s[i] == "find")
        {
            ax = ay = 0;
            query(1, nxt[X[i]], tot, Y[i]);
            if (ax && ay)
                cout << a[ax].x << " " << ay << endl;
            else
                cout << "-1" << endl;
            // cout<<"!!"<<t[1].val<<endl;
        }
        if (s[i] == "remove")
        {
            rem(1, X[i]);
        }
    }
    return 0;
}
