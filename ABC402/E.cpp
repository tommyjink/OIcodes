#include <bits/stdc++.h>
using namespace std;
const int N = 10, M = 1e4;
int c[N];
double dp[1 << N][M], s[N], p[N];
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> s[i] >> c[i] >> p[i];
    for (int j = 0; j <= x; j++)
        for (int k = 0; k < (1 << n); k++)
            for (int i = 0; i < n; i++)
                if (j >= c[i] && !(k & (1 << i)))
                    dp[k][j] = max(dp[k][j], (p[i] / 100.0) * (s[i] + dp[k | (1 << i)][j - c[i]]) + ((100.0 - p[i]) / 100.0) * dp[k][j - c[i]]);
    printf("%lf", dp[0][x]);
    return 0;
}