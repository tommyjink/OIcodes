#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int t[N << 2];
int a[N], L[N], lst[N];
int n, q;

inline void modify(int p, int l, int r, int x, int w) {
    if (l == r) { t[p] = w; return; }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(p << 1, l, mid, x, w);
    else modify(p << 1 | 1, mid + 1, r, x, w);
    t[p] = max(t[p << 1], t[p << 1 | 1]);
}

inline int query(int p, int l, int r, int s, int e) {
    if (e < s) return 0;
    if (s <= l && r <= e) return t[p];
    int mid = (l + r) >> 1, res = 0;
    if (s <= mid) res = query(p << 1, l, mid, s, e);
    if (e > mid) res = max(res, query(p << 1 | 1, mid + 1, r, s, e));
    return res;
}

inline void clear(int p, int l, int r) {
    t[p] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    clear(p << 1, l, mid);
    clear(p << 1 | 1, mid + 1, r);
}

inline void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    memset(lst, 0, sizeof(lst));
    clear(1, 1, n);
    for (int i = 1, l = 1; i <= n; ++i) {
        int r = lst[a[i]];
        while (query(1, 1, n, l, r) > r) ++l;
        if (r) modify(1, 1, n, r, i);
        L[i] = l;
        lst[a[i]] = i;
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        puts(L[r] <= l ? "YES" : "NO");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}