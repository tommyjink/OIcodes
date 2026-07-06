#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 10, INF = 1e13;
int n, m, a[N], b[N];
struct node
{
    int l, r, va, vb;
} t[N * 4];
void pushup(int k)
{
    if (t[k * 2].va <= a[t[k * 2 + 1].l])
        t[k].va = t[k * 2 + 1].va;
    else if (t[k * 2].va <= b[t[k * 2 + 1].l])
        t[k].va = t[k * 2 + 1].vb;
    else
        t[k].va = INF;
    if (t[k * 2].vb <= a[t[k * 2 + 1].l])
        t[k].vb = t[k * 2 + 1].va;
    else if (t[k * 2].vb <= b[t[k * 2 + 1].l])
        t[k].vb = t[k * 2 + 1].vb;
    else
        t[k].vb = INF;
}
void build(int k, int l, int r)
{
    t[k].l = l, t[k].r = r;
    if (l == r)
    {
        t[k].va = a[l];
        t[k].vb = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    pushup(k);
}
void update(int k, int x)
{
    if (t[k].l > x || t[k].r < x)
        return;
    if (t[k].l == t[k].r)
    {
        t[k].va = a[t[k].l];
        t[k].vb = b[t[k].l];
        return;
    }
    update(k * 2, x);
    update(k * 2 + 1, x);
    pushup(k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = min(x, y);
        b[i] = max(x, y);
    }
    build(1, 1, n);
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        swap(a[x], a[y]);
        swap(b[x], b[y]);
        update(1, x);
        update(1, y);
        if (t[1].va < INF || t[1].vb < INF)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    return 0;
}