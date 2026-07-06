#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 20, K = 150, M = 1e5;
int kk, n, s[N];
double f[K][M], p[N], r = 0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> kk >> n;
    r = 1.0 / (double)kk;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        while (true)
        {
            int x;
            cin >> x;
            if (!x)
                break;
            s[i] |= (1ll << (x - 1));
        }
    }
    for (int i = kk; i >= 1; i--)
        for (int j = 0; j < (1 << n); j++)
        {
            for (int k = 1; k <= n; k++)
                if ((j & s[k]) == s[k])
                    f[i][j] += max(f[i + 1][j], f[i + 1][j | (1 << k - 1)] + p[k]);
                else
                    f[i][j] += f[i + 1][j];
            f[i][j] /= n;
        }
    // cout<<f[1][0]<<endl;
    printf("%.6lf",f[1][0]);
    return 0;
}