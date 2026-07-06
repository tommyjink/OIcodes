
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int T, n, k, X, Y;
int x[N], y[N], s[N], l[N], r[N];

void get(int ox, int oy) {
    int pos = ox * X + oy * Y;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + ox * x[i] + oy * y[i] + k;
    if (!s[n]) {
        for (int i = 1; i <= n; i++) if (s[i] < pos) r[i] = -1;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (s[n] > 0) {
            if (s[i] < pos) l[i] = max(l[i], ((pos - s[i]) % s[n] ? (pos - s[i]) / s[n] + 1 : (pos - s[i]) / s[n]));
        } else {
            if (s[i] < pos) r[i] = -1;
            else r[i] = min(r[i], (pos - s[i]) / s[n]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k >> X >> Y;
        for (int i = 1; i <= n; i++) cin >> x[i] >> y[i], l[i] = 0, r[i] = 1e15;
        if (!X && !Y) {
            cout << 0 << '\n';
            continue;
        }
        get(1, 1);
        get(1, -1);
        get(-1, -1);
        get(-1, 1);
        int ans = 1e18;
        for (int i = 1; i <= n; i++) if (l[i] <= r[i]) ans = min(ans, l[i] * n + i);
        if (ans == 1e18) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
