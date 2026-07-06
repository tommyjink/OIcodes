#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 3005, M = 15;
int n, K, f[N][N][2], k,now=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> f[i][j][0];
    for (k = 1; (1ll << k) <= K; k++)
    {
        now^=1;
        int kk = (1ll << k), p = (1ll << (k - 1));
        for (int i = 1; i + kk - 1 <= n; i++)
            for (int j = 1; j <= i && j + kk - 1 <= n; j++)
            {
                f[i][j][now] = max(f[i][j][now], f[i][j][now^1]);
                f[i][j][now] = max(f[i][j][now], f[i + p][j][now^1]);
                f[i][j][now] = max(f[i][j][now], f[i + p][j + p][now^1]);
                f[i][j][now] = max(f[i][j][now], f[i + p / 2][j][now^1]);
                f[i][j][now] = max(f[i][j][now], f[i + p / 2][j + p / 2][now^1]);
                f[i][j][now] = max(f[i][j][now], f[i + p][j + p / 2][now^1]);
            }
    }
    k--;
    int kk = K, p = (K-(1ll<<k));
    long long tot=0;
    for (int i = 1; i + kk - 1 <= n; i++)
        for (int j = 1; j <= i && j + kk - 1 <= n; j++)
        {
            int ans=0;
            ans = max(ans, f[i][j][now]);
            ans = max(ans, f[i + p][j][now]);
            ans = max(ans, f[i + p][j + p][now]);
            ans = max(ans, f[i + p / 2][j][now]);
            ans = max(ans, f[i + p / 2][j + p / 2][now]);
            ans = max(ans, f[i + p][j + p / 2][now]);
            tot+=ans;
        }
    cout<<tot<<endl;
    return 0;
}