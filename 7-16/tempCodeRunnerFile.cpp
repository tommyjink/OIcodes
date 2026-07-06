
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 ,K = 1e3;
int a[N], b[N];
int dp[N][K][2], lst[N][K][2];
int inf = LLONG_MIN / 2;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int subtask, test;
    cin >> subtask >> test;
    while (test--) {
        int n, k, t, p;
        cin >> n >> k >> t >> p;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                for (int s = 0; s < 2; s++) {
                    dp[i][j][s] = inf;
                    lst[i][j][s] = -1;
                }
        dp[1][0][0] = a[1];
        dp[1][0][1] = b[1];
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = 0; s < 2; s++) {
                    int pre = s;
                    if (dp[i - 1][j][pre] != inf) {
                        int val = dp[i - 1][j][pre] + (s == 0 ? a[i] : b[i]);
                        if (val > dp[i][j][s]) {
                            dp[i][j][s] = val;
                            lst[i][j][s] = lst[i - 1][j][pre];
                        }
                    }
                    if (j == 0) continue;
                    int pre2 = 1 - s;
                    if (dp[i - 1][j - 1][pre2] != inf) {
                        int prei = lst[i - 1][j - 1][pre2];
                        int add = 0;
                        if (prei != -1) {
                            int d = (i - 1) - prei;
                            if (d <= t) add = p;
                        }
                        int val = dp[i - 1][j - 1][pre2] + (s == 0 ? a[i] : b[i]) + add;
                        if (val > dp[i][j][s]) {
                            dp[i][j][s] = val;
                            lst[i][j][s] = i - 1;
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 0; j <= k; j++)
            for (int s = 0; s < 2; s++)
                ans = max(ans, dp[n][j][s]);
        cout << ans << '\n';
    }
    return 0;
}