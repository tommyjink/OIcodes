
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, a[N], b[N], cnt[N], deg[N], pos[N], tot;
vector<pair<int, int>> G[N];
bool vis[N];

void dfs(int u)
{
    while (!G[u].empty())
    {
        int v = G[u].back().first, id = G[u].back().second;
        G[u].pop_back();
        if (vis[id])
            continue;
        pos[id] = u;
        vis[id] = 1;
        dfs(v);
    }
}

void solve()
{
    scanf("%d", &n);
    tot = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), cnt[a[i]]++, deg[a[i]]++;
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]), cnt[b[i]]++, deg[b[i]]++;
    for (int i = 1; i <= n; i++)
        vis[++tot] = 0, G[a[i]].push_back({b[i], tot}), G[b[i]].push_back({a[i], tot});
    for (int i = 1; i <= 2 * n; i++)
        if (deg[i] & 1)
            vis[++tot] = 0, G[0].push_back({i, tot}), G[i].push_back({0, tot});
    for (int i = 0; i <= 2 * n; i++)
        dfs(i);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
        ans += min(cnt[i], 2), cnt[i] = 0;
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
    {
        int s = a[i] + b[i];
        a[i] = pos[i];
        b[i] = s - pos[i];
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", a[i], " \n"[i == n]);
    for (int i = 1; i <= n; i++)
        printf("%d%c", b[i], " \n"[i == n]);
    for (int i = 0; i <= 2 * n; i++)
        G[i].clear(), deg[i] = 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
