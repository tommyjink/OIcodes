#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 10, M = 55;
int n, m, k, head[N], tot = 0, a, b, wa, wb, val[N];
int dp[N][M], in[N], ans = -1e9;
struct node
{
    int to, next, from;
} e[N * 2];
void add(int x, int y)
{
    e[++tot] = (node){y, head[x], x};
    head[x] = tot;
}
void topo()
{
    dp[1][0] = val[1];
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = head[t]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (!--in[v]) q.push(v);
            for (int j = 1; j <= max(a, b); j++)
                if (dp[t][j - 1] > -1e9) dp[v][j] = max(dp[v][j], dp[t][j - 1]);
            if (dp[t][a - 1] > -1e9) dp[v][0] = max(dp[v][0], dp[t][a - 1] + val[v] - wa);
            if (dp[t][b - 1] > -1e9) dp[v][0] = max(dp[v][0], dp[t][b - 1] + val[v] - wb);
            ans = max(ans, dp[v][0]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n >> m >> a >> b >> wa >> wb;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        val[x] += y;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        in[y]++;
    }
    memset(dp, 128, sizeof(dp));
    topo();
    cout << ans << endl;
    return 0;
}