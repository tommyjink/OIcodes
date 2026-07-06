#include<bits/stdc++.h>
using namespace std;

#define int long long

const int P = 998244353;

void solve() {
    int k;
    cin >> k;

    int ans = 0;
    for (int a = 2; a <= k - 4; ++a) {
        for (int b = 2; a + b <= k - 2; ++b) {
            int c = k - a - b;
            int f_g = min({a + b, b + c, c + a});
            int ways = (a - 1) * (b - 1) % P * (c - 1) % P;
            ans = (ans + f_g * ways) % P;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}