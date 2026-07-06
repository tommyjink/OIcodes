#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int INF = 1e9;

int n, k;
int a[MAXN][5];

struct Node {
    int mx[32], mn[32];
} tree[MAXN << 2];

void pushup(int p) {
    for (int i = 0; i < (1 << k); ++i) {
        tree[p].mx[i] = max(tree[p << 1].mx[i], tree[p << 1 | 1].mx[i]);
        tree[p].mn[i] = min(tree[p << 1].mn[i], tree[p << 1 | 1].mn[i]);
    }
}

void build(int p, int l, int r) {
    if (l == r) {
        for (int i = 0; i < (1 << k); ++i) {
            int val = 0;
            for (int j = 0; j < k; ++j) {
                if ((i >> j) & 1) val += a[l][j];
                else val -= a[l][j];
            }
            tree[p].mx[i] = tree[p].mn[i] = val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int x, int b[]) {
    if (l == r) {
        for (int i = 0; i < (1 << k); ++i) {
            int val = 0;
            for (int j = 0; j < k; ++j) {
                if ((i >> j) & 1) val += b[j];
                else val -= b[j];
            }
            tree[p].mx[i] = tree[p].mn[i] = val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(p << 1, l, mid, x, b);
    else update(p << 1 | 1, mid + 1, r, x, b);
    pushup(p);
}

Node query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(p << 1, l, mid, ql, qr);
    if (ql > mid) return query(p << 1 | 1, mid + 1, r, ql, qr);
    
    Node left = query(p << 1, l, mid, ql, qr);
    Node right = query(p << 1 | 1, mid + 1, r, ql, qr);
    Node res;
    for (int i = 0; i < (1 << k); ++i) {
        res.mx[i] = max(left.mx[i], right.mx[i]);
        res.mn[i] = min(left.mn[i], right.mn[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) cin >> a[i][j];
    }

    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int i, b[5];
            cin >> i;
            for (int j = 0; j < k; ++j) cin >> b[j];
            update(1, 1, n, i, b);
        } else {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            int ans = 0;
            for (int i = 0; i < (1 << k); ++i) {
                ans = max(ans, res.mx[i] - res.mn[i]);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}