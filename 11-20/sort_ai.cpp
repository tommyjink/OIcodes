#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int P = 1e9 + 7;
const int MAXN = 1e6 + 10;

int fac[MAXN], inv_fac[MAXN], cat[MAXN];

struct SegmentTree {
    struct Node {
        int l, r;
        int val;
        int lazy;
    }tree[MAXN << 2];

    int qpow(int x, int y) {
        int res = 1;
        while(y) {
            if(y & 1) res = res * x % P;
            x = x * x % P;
            y >>= 1;
        }
        return res;
    }

    void pushup(int k) {
        tree[k].val = (tree[k << 1].val + tree[k << 1 | 1].val) % P;
    }

    void pushdown(int k) {
        if(tree[k].lazy == 0) return;
        Node& left = tree[k << 1], &right = tree[k << 1 | 1];

        left.lazy = (left.lazy + tree[k].lazy) % P;
        left.val = (left.val + tree[k].lazy * (left.r - left.l + 1)) % P;

        right.lazy = (right.lazy + tree[k].lazy) % P;
        right.val = (right.val + tree[k].lazy * (right.r - right.l + 1)) % P;

        tree[k].lazy = 0;
    }

    void build(int k, int l, int r, const vector<int>& a) {
        tree[k].l = l;
        tree[k].r = r;
        tree[k].lazy = 0;
        if(l == r) {
            tree[k].val = a[l] % P;
            return;
        }
        int mid = (l + r) >> 1;
        build(k << 1, l, mid, a);
        build(k << 1 | 1, mid + 1, r, a);
        pushup(k);
    }

    void update(int k, int L, int R, int d) {
        if(tree[k].r < L || tree[k].l > R) return;
        if(L <= tree[k].l && tree[k].r <= R) {
            tree[k].lazy = (tree[k].lazy + d) % P;
            tree[k].val = (tree[k].val + d * (tree[k].r - tree[k].l + 1)) % P;
            return;
        }
        pushdown(k);
        update(k << 1, L, R, d);
        update(k << 1 | 1, L, R, d);
        pushup(k);
    }

    int query(int k, int L, int R) {
        if(tree[k].r < L || tree[k].l > R) return 0;
        if(L <= tree[k].l && tree[k].r <= R) return tree[k].val % P;
        pushdown(k);
        int left_res = query(k << 1, L, R);
        int right_res = query(k << 1 | 1, L, R);
        return (left_res + right_res) % P;
    }
};

void init_cat() {
    fac[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % P;
    }
    inv_fac[MAXN - 1] = SegmentTree().qpow(fac[MAXN - 1], P - 2);
    for(int i = MAXN - 2; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % P;
    }
    cat[0] = 1;
    for(int k = 1; k <= 5e5; k++) {
        int C = fac[2 * k] * inv_fac[k] % P;
        C = C * inv_fac[k] % P;
        int inv_k1 = SegmentTree().qpow(k + 1, P - 2);
        cat[k] = C * inv_k1 % P;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_cat();

    int n, m;
    cin >> n >> m;
    int total_len = 2 * n;

    vector<int> a(total_len + 1);
    for(int i = 1; i <= total_len; i++) {
        cin >> a[i];
    }

    SegmentTree st1, st2;
    st1.build(1, 1, total_len, a);

    vector<int> diff(n + 1);
    for(int i = 1; i <= n; i++) {
        diff[i] = (a[2 * i] - a[2 * i - 1]) % P;
        if(diff[i] < 0) diff[i] += P;
    }
    st2.build(1, 1, n, diff);

    while(m--) {
        int op;
        cin >> op;
        if(op == 0) {
            int l, r, val;
            cin >> l >> r >> val;
            val %= P;

            st1.update(1, l, r, val);

            int diff_l = (l + 1) / 2;
            int diff_r = r / 2;
            if(diff_l <= diff_r) {
                st2.update(1, diff_l, diff_r, 0);
            }
        } else {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            int k = len / 2;

            int sum_right = st1.query(1, r - k + 1, r);
            int sum_left = st1.query(1, l, l + k - 1);
            int max_gap = (sum_right - sum_left) % P;
            if(max_gap < 0) max_gap += P;

            int diff_l = (l + 1) / 2;
            int diff_r = r / 2;
            int min_gap = st2.query(1, diff_l, diff_r) % P;
            if(min_gap < 0) min_gap += P;

            int plan = cat[k] % P;

            cout << max_gap << " " << min_gap << " " << plan << endl;
        }
    }

    return 0;
}