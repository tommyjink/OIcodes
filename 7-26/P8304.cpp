
#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;
int pre[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i-1] + (s[i] == '1');
    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt1 = pre[r] - pre[l-1];
        int cnt0 = (r-l+1) - cnt1;
        if (!cnt1) cout << "-1\n";
        else {
            int m = min(cnt0, cnt1);
            int ans = (cnt1 >= m+1) ? 2*m+1 : 2*m;
            cout << ans << '\n';
        }
    }
    return 0;
}