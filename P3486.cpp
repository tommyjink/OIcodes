#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e3,INF=1e15;
int n, K, a[N][N], b[N][N], f[N][N], sav[N][N];
int ans = 0;
vector<int> final;
int cal(int x, int y, int xx, int yy)
{
    x--, y--;
    return b[xx][yy] - b[xx][y] - b[x][yy] + b[x][y];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            f[i][j]=-INF;
    f[0][0]=0;
    cin >> n >> K;
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 1; k <= min(K, i); k++)
            {
                if (f[j][k - 1] + cal(j + 1, i + 1, i, n) > f[i][k])
                {
                    sav[i][k] = j;
                    f[i][k] = f[j][k - 1] + cal(j + 1, i + 1, i, n);
                }
            }
        }
        if (f[i][K] > f[ans][K])
            ans = i;
    }
    while (ans)
    {
        final.push_back(ans);
        ans = sav[ans][K--];
    }
    for (int i = final.size() - 1; i >= 0; i--)
        cout << final[i] << " ";
    return 0;
}