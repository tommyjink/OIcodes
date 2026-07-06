#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        vector<int> cnt;
        for (auto& p : freq) {
            cnt.push_back(p.second);
        }
        sort(cnt.begin(), cnt.end());
        
        // 计算所有可能的子集大小
        vector<int> possible_sizes;
        for (int k = 1; k <= n; k++) {
            bool valid = true;
            // 检查是否可以将集合划分为k个子集，每个子集都有众数
            // 关键条件: 最大频率不能超过 n - k + 1
            // 因为最大的子集最多可以有 n - k + 1 个元素
            int max_freq = *max_element(cnt.begin(), cnt.end());
            if (max_freq > n - k + 1) {
                valid = false;
            }
            if (valid) {
                possible_sizes.push_back(k);
            }
        }
        
        // 使用动态规划计算生成函数系数
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int c : cnt) {
            vector<int> new_dp = dp;
            for (int i = n; i >= 0; i--) {
                if (dp[i] == 0) continue;
                for (int j = 1; j <= c && i + j <= n; j++) {
                    new_dp[i + j] = (new_dp[i + j] + dp[i]) % MOD;
                }
            }
            dp = new_dp;
        }
        
        int ans = 0;
        for (int k : possible_sizes) {
            ans = (ans + dp[k]) % MOD;
        }
        
        cout << ans << '\n';
    }

    return 0;
}