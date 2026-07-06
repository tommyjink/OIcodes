#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1005, M = N * N, INF = 1e16;
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int n, m, s, t, tot = 1, head[M], ban[N][N];
int dis[M], now[M];
inline int cal(int x, int y) { return (x - 1) * n + y; }
struct node
{
    int to, next, val;
} e[M * 8];
void add(int x, int y, int z)
{
    e[++tot] = (node){y, head[x], z}, head[x] = tot;
    e[++tot] = (node){x, head[y], 0}, head[y] = tot;
}
queue<int> q;
bool bfs()
{
    for (int i = 1; i <= t; i++)
        dis[i] = INF, now[i] = head[i];
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] == INF && e[i].val)
                dis[v] = dis[x] + 1, q.push(v);
        }
    }
    return dis[t] != INF;
}
int dfs(int x, int sum)
{
    int res = 0;
    if (x == t)
        return sum;
    for (int i = now[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        now[x] = i;
        if (!e[i].val || dis[x] + 1 != dis[v])
            continue;
        int k = dfs(v, min(sum, e[i].val));
        e[i].val -= k, e[i ^ 1].val += k;
        sum -= k, res += k;
    }
    return res;
}
int maxflow()
{
    int res = 0;
    while (bfs())
        res += dfs(s, INF);
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ban[x][y] = true;
    }
    s = n * n + 1, t = n * n + 2;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (ban[x][y])
                continue;
            if ((x + y) & 1)
            {
                add(s, cal(x, y), 1);
                for (int i = 0; i < 8; i++)
                {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (xx < 1 || yy < 1 || xx > n || yy > n)
                        continue;
                    if (ban[xx][yy])
                        continue;
                    add(cal(x, y), cal(xx, yy), INF);
                }
            }
            else
                add(cal(x, y), t, 1);
        }
    }
    cout << n * n - m - maxflow() << endl;
    return 0;
}