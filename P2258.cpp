#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 18;
int n, m, r, c, a[N][N], s[N];
int X[N], Y[N][N], f[N][N], ans = 1e9;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    // f[i][j]前i列取j列，取第i列
    for (int p = 0; p < (1 << n); p++)
    {
        int tot = 0;
        for (int i = 1; i <= n; i++)
            if (p & (1 << (i - 1)))
                s[++tot] = i;
        if (tot != r)
            continue;
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(f, 0, sizeof(f));
        memset(f, 127, sizeof(f));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j < tot; j++)
                X[i] += abs(a[s[j]][i] - a[s[j + 1]][i]);
            f[i][1] = X[i];
            for (int j = i + 1; j <= m; j++)
                for (int k = 1; k <= tot; k++)
                    Y[i][j] += abs(a[s[k]][i] - a[s[k]][j]);
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= min(c, i); j++)
                for (int k = 1; k < i; k++)
                    f[i][j] = min(f[i][j], f[k][j - 1] + X[i] + Y[k][i]);
            ans = min(ans, f[i][c]);
        }
    }
    cout << ans << endl;
    return 0;
}