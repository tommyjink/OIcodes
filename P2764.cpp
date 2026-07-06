#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 5005, INF = 1e16;
int n, m, s, t, head[N], tot = 1;
int dis[N], now[N];

int nxt[N];
bool in[N];

struct node
{
    int to, next, val;
} e[N * 10];

void add(int x, int y, int z)
{
    e[++tot] = {y, head[x], z};
    head[x] = tot;
    e[++tot] = {x, head[y], 0};
    head[y] = tot;
}

queue<int> q;
bool bfs()
{
    for (int i = 0; i <= t; i++)
        dis[i] = INF, now[i] = head[i];
    while (!q.empty())
        q.pop();
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
            {
                dis[v] = dis[x] + 1;
                q.push(v);
            }
        }
    }
    return dis[t] != INF;
}

int dfs(int x, int sum)
{
    if (x == t || sum == 0)
        return sum;
    int res = 0;

    for (int i = now[x]; i && sum > 0; i = e[i].next)
    {
        now[x] = i;
        int v = e[i].to;
        if (dis[v] != dis[x] + 1 || !e[i].val)
            continue;

        int k = dfs(v, min(sum, e[i].val));
        if (k == 0)
            dis[v] = INF;

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

    s = 0, t = 2 * n + 1;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y + n, 1);
    }
    for (int i = 1; i <= n; i++)
        add(s, i, 1);
    for (int i = 1; i <= n; i++)
        add(i + n, t, 1);

    int res = maxflow();

    for (int u = 1; u <= n; u++)
    {
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;

            if (v > n && v <= 2 * n && e[i].val == 0)
            {
                nxt[u] = v - n;
                in[v - n] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {

        if (!in[i])
        {
            int curr = i;
            while (curr)
            {
                cout << curr << " ";
                curr = nxt[curr];
            }
            cout << endl;
        }
    }

    cout << n - res << endl;
    return 0;
}