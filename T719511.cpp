#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;

inline int read() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x;
}

const int N = 1e5 + 10;
int n, k;
struct node {
    int x, y, z, id;
} a[N], b[N];

bool cmp(node a, node b) {
    if (a.x == b.x) {
        if (a.y == b.y) return a.id < b.id;
        return a.y < b.y;
    }
    return a.x < b.x;
}

int qt[1005], qs[1005], qc;

void solve() {
    n = read(); k = read();
    for (int i = 1; i <= n; i++) {
        a[i].x = read(); a[i].y = read(); a[i].z = read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);

    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (i < n && a[i].x == a[i + 1].x && a[i].y == a[i + 1].y) continue;
        b[++now] = a[i];
    }
    n = now;

    qc = 0;
    for (int l = 1, r; l <= k; l = r + 1) {
        int h = k / l;
        if (h == 0) break;
        r = k / h;
        qt[++qc] = r;
        qs[qc] = 0;
        l = r;
    }

    for (int l = 1; l <= n; ) {
        int r = l;
        while (r <= n && b[r].x == b[l].x) r++;
        
        int total = 0;
        for(int i = l; i < r; i++) total += b[i].z;

        for (int i = 1; i <= qc; i++) {
            if (total <= qs[i]) continue;
            int t = qt[i];
            int right = l, res = 0;
            for (int left = l; left < r; left++) {
                while (right < r && b[right].y - b[left].y <= t) {
                    res += b[right].z;
                    right++;
                }
                if (res > qs[i]) qs[i] = res;
                res -= b[left].z;
                if (res + (total - res) <= qs[i] && right == r) break;
            }
        }
        l = r;
    }

    int ans = 0;
    for (int i = 1; i <= qc; i++) {
        int cur = qs[i] * (k / qt[i]);
        if (cur > ans) ans = cur;
    }
    printf("%lld\n", ans);
}

signed main() {
    int t = read();
    while (t--) solve();
    return 0;
}