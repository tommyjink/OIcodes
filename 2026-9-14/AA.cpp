#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, a[500005], cnt;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (cnt + 1 == a[i]) cnt++;
    }
    cout << n - cnt << "\n";
    return ;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    T = 1;
    while (T--) solve();
    return 0;
}