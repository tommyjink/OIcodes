#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, n, k, a[N], s[N], c[N], mn, mx, nw;
inline bool chk(int mid, int &l, int &r)
{
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + (a[i] >= mid ? 1 : -1);
    int mm = n + 1, ll = 0;
    for (int i = k; i <= n; ++i)
    {
        if (s[i - k] < mm)
            mm = s[i - k], ll = i - k;
        if (s[i] >= mm)
            return l = ll + 1, r = i, 1;
    }
    return 0;
}
inline void sol(int &ans, int &l, int &r)
{
    int L = 1, R = n;
    while (L < R)
    {
        int mid = (L + R + 1) >> 1;
        if (chk(mid, l, r))
            L = mid;
        else
            R = mid - 1;
    }
    chk(L, l, r), ans = L;
}
inline void add(int x, int k)
{
    c[x] += k, nw += x >= mn ? k : -k;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l1, r1, l2, r2;
    for (int i = 1; i <= n; ++i)
        a[i] = n - a[i] + 1;
    sol(mn, l1, r1);
    mn = n - mn + 1;
    for (int i = 1; i <= n; ++i)
        a[i] = n - a[i] + 1;
    sol(mx, l2, r2);
    for (int i = l1; i <= r1; ++i)
        c[a[i]]++, nw += a[i] >= mn ? 1 : -1;
    cout << mx - mn + 1 << '\n';
    while (mn <= mx)
    {
        while (nw >= 0)
            cout << mn << ' ' << l1 << ' ' << r1 << '\n', nw -= 2 * c[mn++];
        if (l1 > l2)
            add(a[--l1], 1);
        else if (r1 < r2)
            add(a[++r1], 1);
        else if (l1 < l2)
            add(a[l1++], -1);
        else if (r1 > r2)
            add(a[r1--], -1);
    }

    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    nw = 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
