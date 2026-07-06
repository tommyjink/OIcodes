#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3010;
int n, W;
pair<int, int> treasure[N];
int dp[N][N];
int cnt[N];

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> treasure[i].first >> treasure[i].second;
    }
    sort(treasure + 1, treasure + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= treasure[i].first) {
                int tmp = dp[i][j - treasure[i].first];
                if (tmp + treasure[i].second - cnt[i] > dp[i - 1][j]) {
                    dp[i][j] = tmp + treasure[i].second - cnt[i];
                    cnt[i]++;
                }
            }
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}