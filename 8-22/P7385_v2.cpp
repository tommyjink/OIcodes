#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P = 1e9 + 7;
const int N = 1e5 + 10;

int n, a, b, m;
int ex[N], f[N], g[N];  // f[i]:前i步总期望；g[i]:第i步前的计数器期望
int p;  // 成功跳上下一格的概率(a+b)

int qpow(int x, int y) {
    int res = 1;
    x %= P;
    while (y) {
        if (y & 1) res = res * x % P;
        x = x * x % P;
        y >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b >> m;
    
    int inv100 = qpow(100, P - 2);
    a = a * inv100 % P;  // 没跳中心概率
    b = b * inv100 % P;  // 跳中心概率
    p = (a + b) % P;     // 成功跳跃概率
    
    memset(ex, 0, sizeof(ex));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= n) ex[x] = y;
    }
    
    g[1] = 2;  // 第1步前的计数器是2
    f[0] = 0;  // 0步得分0
    
    for (int i = 1; i <= n; i++) {
        // 第i步的贡献：必须前i-1步都成功，第i步才可能有贡献
        int pre_prob = (i == 1) ? 1 : qpow(p, i - 1);  // 前i-1步成功概率
        
        // 1. 没跳中心得分：1分 * 概率a * 前序成功概率
        int add1 = pre_prob * a % P * 1 % P;
        
        // 2. 跳中心得分：(当前计数器 + 特殊分) * 概率b * 前序成功概率
        int add2 = pre_prob * b % P * (g[i] + ex[i]) % P;
        
        // 总得分：前i-1步得分 + 第i步得分
        f[i] = (f[i - 1] + add1 + add2) % P;
        
        // 更新第i+1步前的计数器期望：仅当第i步成功时才会进入第i+1步
        // 跳中心则翻倍，没跳中心则重置为2，权重为条件概率
        if (i < n) {
            // 条件概率：在第i步成功的前提下，跳中心/没跳中心的概率
            int cond_b = b * qpow(p, P - 2) % P;  // b/p
            int cond_a = a * qpow(p, P - 2) % P;  // a/p
            g[i + 1] = (cond_b * 2 % P * g[i] % P + cond_a * 2 % P) % P;
        }
    }
    
    cout << f[n] << endl;
    return 0;
}