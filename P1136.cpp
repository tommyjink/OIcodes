#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
const int N = 505, K = 105;
int n, m, f[N][K][K][3];
char s[N];
int main()
{
    scanf("%d%d%s", &n, &m, s + 1);
    memset(f, 0x80, sizeof f);
    f[0][0][0][1] = 0;
    rep(i, 1, n)
    {
        rep(j, 0, m)
        {
            rep(k, 0, m)
            {
                if (s[i] == 'z')
                {
                    f[i][j][k][1] = max(f[i - 1][j][k][0] + 1, f[i - 1][j][k][1]);
                    if (k)
                        f[i][j][k][0] = max(f[i - 1][j][k - 1][0], f[i - 1][j][k - 1][1]);
                }
                else
                {
                    f[i][j][k][0] = max(f[i - 1][j][k][0], f[i - 1][j][k][1]);
                    if (j)
                        f[i][j][k][1] = max(f[i - 1][j - 1][k][0] + 1, f[i - 1][j - 1][k][1]);
                }
            }
        }
    }
    int ans = 0;
    rep(i, 0, m) ans = max(ans, max(f[n][i][i][1], f[n][i][i][0]));
    printf("%d\n", ans);
    return 0;
}
