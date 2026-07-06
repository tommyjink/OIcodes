#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 100;
const int dx0[2] = {1, 0};
const int dy0[2] = {0, 1};
const int dx1[2] = {-1, 0};
const int dy1[2] = {0, -1};
int n, M, a[N][N], ans = 0, val[N];
vector<int> b[N][N];
void dfs(int x, int y, int k, int l, int now, int mode)
{
    if (k == l)
    {
        if (mode == 0)
            b[x][y].push_back((now * 10 + a[x][y])%M*val[l]%M);
        else 
        {
            int p=upper_bound(b[x][y].begin(),b[x][y].end(),M-now)-b[x][y].begin()-1;
            if(p>=0&&p<b[x][y].size())
                ans=max(ans,(now+b[x][y][p])%M);
            ans=max(ans,(now+b[x][y].back())%M);
            ans=max(ans,(now+b[x][y][max(0ll,(int)b[x][y].size()-2)])%M);
        }
        return;
    }
    if (mode == 0) now = (now * 10 + a[x][y]) % M;
    else
        now = (now + a[x][y] * val[k]) % M;
    for (int i = 0; i < 2; i++)
    {
        int xx = x + dx1[i], yy = y + dy1[i];
        if (mode == 0) xx = x + dx0[i], yy = y + dy0[i];
        if (xx > n || yy > n || xx < 1 || yy < 1) continue;
        dfs(xx, yy, k + 1, l, now % M, mode);
    }
}
signed main()
{
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> M;
    val[0] = 1;
    for (int i = 1; i < N; i++) 
        val[i] = val[i - 1] * 10 % M;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dfs(1, 1, 0, n - 1, 0, 0);
    for (int i = 1; i <= n; i++)
        sort(b[i][n - i + 1].begin(), b[i][n - i + 1].end());
    dfs(n, n, 0, n - 1, 0, 1);
    cout << ans << endl;
    return 0;
}