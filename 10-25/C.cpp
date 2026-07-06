#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005, M = 998244353;
int n, b[N], f[N][N], jc[N * 2], nj[N * 2];
int ksm(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
            r = r * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return r;
}
int C(int n, int m)
{
    if (m < 0 || m > n)
        return 0;
    return jc[n] * nj[m] % M * nj[n - m] % M;
}
signed main()
{
    jc[0] = 1;
    for (int i = 1; i < N * 2; i++)
        jc[i] = jc[i - 1] * i % M;
    nj[N * 2 - 1] = ksm(jc[N * 2 - 1], M - 2);
    for (int i = N * 2 - 2; i >= 0; i--)
        nj[i] = nj[i + 1] * (i + 1) % M;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++)
        cin >> b[i], s += b[i];
    if (s & 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    int m = s / 2;
    for (int i = 1; i <= n; i++)
        if (b[i] > m)
        {
            cout << 0 << '\n';
            return 0;
        }
    f[0][0] = 1;
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= pre; j++)
        {
            if (!f[i - 1][j])
                continue;
            for (int k = 0; k <= min(b[i], j); k++)
            {
                int w = C(j, k) * C(pre - j, b[i] - k) % M;
                f[i][j + b[i] - k] = (f[i][j + b[i] - k] + f[i - 1][j] * w % M) % M;
            }
        }
        pre += b[i];
    }
    cout << f[n][m] << '\n';
    return 0;
}