#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int maxn = 1000010, mod = 998244353;
int n, ans, ansone, anstwo, ansthr;
int ark[maxn], arknv[maxn];

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = getchar();
    }
    return s * w;
}

inline int qpow(int A, int B)
{
    int Ans = 1;
    while (B)
    {
        if (B & 1)
            Ans = Ans * A % mod;
        A = A * A % mod;
        B >>= 1;
    }
    return Ans;
}

inline void pre()
{
    int p = max(n, 3ll);
    ark[0] = arknv[0] = 1;
    for (int i = 1; i <= p; ++i)
        ark[i] = ark[i - 1] * i % mod;
    arknv[p] = qpow(ark[p], mod - 2);
    for (int i = p - 1; i; --i)
        arknv[i] = arknv[i + 1] * (i + 1) % mod;
}

inline int C(int p, int q)
{
    if (p < q)
        return 0;
    return ark[p] * arknv[p - q] % mod * arknv[q] % mod;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read();
    pre();
    for (int i = 0; i <= n; ++i)
    {
        int v = qpow(3, n - i) % mod, p = (i & 1) ? mod - 1 : 1;
        v = qpow(v, mod - 2) % mod;
        v = qpow(1 - v + mod, n) % mod;
        ansone = (ansone + p % mod * C(n, i) % mod * qpow(3, n * (n - i)) % mod * v % mod);
    }
    ansone = ((qpow(3, n * n) - ansone + mod) % mod + mod) % mod;
    for (int i = 2; i <= n; ++i)
    {
        int p = (i & 1) ? mod - 1 : 1;
        anstwo = (anstwo + p * C(n, i) % mod * (qpow(2, i) - 2 + mod) % mod * qpow(3, (n - i) * n) % mod) % mod;
    }
    anstwo = anstwo * 2 % mod;
    for (int i = 3; i <= n; ++i)
    {
        int p = (i & 1) ? 1 : mod - 1;
        ansthr = (ansthr + p * C(n, i) % mod * ((qpow(3, i) - 3 * (qpow(2, i) - 2) % mod + mod - 3) % mod + mod) % mod * qpow(3, (n - i) * n) % mod) % mod;
    }
    ansthr = ansthr * 2 % mod;
    ans = (((ansone * 3 % mod - anstwo * 3 % mod + mod) % mod + mod) % mod + ansthr) % mod;
    cout << ans << endl;
    return 0;
}