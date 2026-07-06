#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 25, M = 2e6 + 5;
int n, m, a[N][M], b[M], f[N][M], ans = 0;
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[j][i] != -1)
                b[i] |= (1ll << (j - 1));
        for (int j = 1; j <= n; j++)
            if (a[j][i] != -1)
                f[j][b[i]] += a[j][i];
    }

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		for (int k = 0; k <= (1 << n) - 1; k++) {
    			if (!(k & (1 << (j - 1))))f[i][k] += f[i][k | (1 << (j - 1))];
    		}
    	}
    }
    for (int i = 0; i <= (1ll << n) - 1; i++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
            if (i & (1ll << (j - 1)))
                res += f[j][i];
        ans = max(res, ans);
    }
    cout << ans << endl;
    return 0;
}