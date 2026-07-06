
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int inv2 = (mod + 1) >> 1;
const int inv6 = (mod + 1) / 6;
ll dp[15][8][5][3][2][5983];
ll dfs(int n, int t1, int t2, int t3, int t4, int t5, int k)
{
    if (k < 0 || t1 < 0 || t2 < 0 || t3 < 0 || t4 < 0 || t5 < 0)
        return 0;
    if (!k)
        return t1 || t2 || t3 || t4 || t5 ? 0 : 1;
    ll &ans = dp[t1][t2][t3][t4][t5][k];
    if (~ans)
        return ans;
    ans = 0;
    int p = t1 + t2 + t3 + t4 + t5;
    p = p * (n - p + 1);
    ans += dfs(n, t1 - 1, t2, t3, t4, t5, k - 1 * p);
    ans += dfs(n, t1, t2 - 1, t3, t4, t5, k - 2 * p);
    ans += dfs(n, t1, t2, t3 - 1, t4, t5, k - 3 * p);
    ans += dfs(n, t1, t2, t3, t4 - 1, t5, k - 4 * p);
    ans += dfs(n, t1, t2, t3, t4, t5 - 1, k - 5 * p);
    return ans;
}
inline ll calc(ll n, ll m)
{
    n %= mod, m %= mod;
    ll ans = (n + 1) * m % mod * (m + 1) % mod * inv2 % mod;
    ans -= m * (m + 1) % mod * (2 * m + 1) % mod * inv6 % mod;
    return (ans + mod) % mod;
}
ll cnt[61];
inline ll calc(ll n)
{
    ll m = n >> 1, ans = 0;
    for (int i = 0; i < 60; i++)
        cnt[i + 1] = n >> i;
    for (int i = 1; i < 60; i++)
        cnt[i] -= cnt[i + 1];
    if (n & 1)
        ans = (m + 1) % mod * ((n - m) % mod) % mod, cnt[1]--;
    for (int i = 1; i <= 60; i++)
    {
        ll t = cnt[i] >> 1;
        m -= t;
        ans = (ans + 2 * (calc(n, m + t) - calc(n, m) + mod) % mod * i % mod) % mod;
        if (cnt[i] & 1)
        {
            ans = (ans + m % mod * ((n - m + 1) % mod) % mod * i % mod) % mod;
            ans = (ans + m % mod * ((n - m + 1) % mod) % mod * (i + 1) % mod) % mod;
            cnt[i + 1]--, m--;
        }
    }
    for (int i = 0; i < 60; i++)
        cnt[i + 1] = n >> i;
    for (int i = 1; i < 60; i++)
        cnt[i] -= cnt[i + 1];
    return ans;
}
ll fac[16];
int t;
ll n, k, x, y;
int main()
{
    *fac = 1;
    for (int i = 1; i <= 15; i++)
        fac[i] = fac[i - 1] * i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        x = calc(n);
        if (n > 28)
        {
            printf("%lld\n", x);
            continue;
        }
        for (int i = 1; i <= 5; i++)
            k = (k - 1) / fac[cnt[i]] + 1;
        memset(dp, 0xff, sizeof dp);
        while (1)
        {
            y = dfs(n, cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], x);
            if (y >= k)
            {
                printf("%lld\n", x);
                break;
            }
            k -= y, x++;
        }
    }
}
