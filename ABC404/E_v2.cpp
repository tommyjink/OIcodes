#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2005;
int n, c[N], a[N], dp[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    // 初始化 dp 数组
    for (int i = 0; i < n; i++) {
        dp[i] = 1e18;
    }
    dp[0] = 0;
    // 动态规划过程
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) continue;
        for (int j = max(0LL, i - c[i]); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}