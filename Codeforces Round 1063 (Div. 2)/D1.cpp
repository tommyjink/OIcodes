#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 5;
int p[N];
vector<int> L, R;

int qry(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void get_pos(int n, int mq) {
    fill(p, p + n, -1);
    int cnt = 0;
    for (int i = 1; i <= n && cnt < n && i <= mq; ++i) {
        int mex = qry(i, i);
        int x = mex;
        if (x < n && p[x] == -1) {
            p[x] = i;
            cnt++;
        }
    }
}

bool chk(int x, int n) {
    if (x == 0) return 1;
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < x; ++i) {
        if (p[i] == -1) return 0;
        mn = min(mn, p[i]);
        mx = max(mx, p[i]);
    }
    for (int i = 0; i < L.size(); ++i) {
        int l = L[i], r = R[i];
        if (l <= mn && r >= mx) return 1;
    }
    return 0;
}

int find_max(int n) {
    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid, n)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        L.clear();
        R.clear();
        for (int i = 0; i < q; ++i) {
            int a, b;
            cin >> a >> b;
            L.push_back(a);
            R.push_back(b);
        }
        int mq = max(300ll, (n + 1) / 2 + 2);
        get_pos(n, mq);
        int ans = find_max(n);
        cout << "! " << ans << endl;
        cout.flush();
    }
    return 0;
}