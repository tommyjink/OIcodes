#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 5;
int n, m;
int t[N << 2], sum[N];
vector<int> id[N << 2];
#define ls p << 1
#define rs p << 1 | 1
void build(int p, int l, int r)
{
    t[p] = r - l + 1;
    id[p].clear();
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
}
void add(int p, int l, int r, int ql, int qr, int k)
{
    if (ql <= l && r <= qr)
    {
        id[p].push_back(k);
        return;
    }
    int mid = l + r >> 1;
    if (ql <= mid)
        add(ls, l, mid, ql, qr, k);
    if (qr > mid)
        add(rs, mid + 1, r, ql, qr, k);
}
long long ans = 0;
inline void upd(int x)
{
    if (sum[x] == 1)
        ans += x * 1ll * x;
    else if (sum[x] == 0)
        ans -= x * 1ll * x;
}
void modify(int p, int l, int r, int k)
{
    t[p]--;
    if (t[p] == 1)
        for (int x : id[p])
            sum[x] -= r - l, upd(x);
    else if (t[p] == 0)
        for (int x : id[p])
            sum[x]--, upd(x);
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (k <= mid)
        modify(ls, l, mid, k);
    else
        modify(rs, mid + 1, r, k);
}
inline void solve()
{
    cin >> n >> m;
    ans = 0;
    build(1, 1, n);
    for (int i = 1, l, r; i <= m; i++)
        cin >> l >> r, l++, r++, sum[i] = r - l + 1, upd(i), add(1, 1, n, l, r, i);
    cout << ans << ' ';
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        x = (x + ans) % n + 1;
        modify(1, 1, n, x);
        cout << ans << ' ';
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}