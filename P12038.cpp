#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 35;
int n, mod, d[N], a[N], sz[N], rt, ans, b[N], len, f[N], v[N], dfn[N], id[N], t, R[N];
vector<int> g[N], s, S[2];
inline void upd(int &x, int y)
{
    x += y;
    while (x >= mod)
        x -= mod;
}
inline void ins(int x) { s.insert(upper_bound(s.begin(), s.end(), x), x); }
inline void dfs(int u, int fa, int op)
{
    sz[u] = 1;
    d[u] = fa;
    if (op)
        dfn[u] = ++t, id[t] = u;
    int val = 0;
    for (auto v : g[u])
    {
        if (v == d[u])
            continue;
        dfs(v, u, op);
        sz[u] += sz[v];
        val = max(val, sz[v]);
    }
    val = max(val, n - sz[u]);
    if (val <= n / 2)
        rt = u;
    if (op)
        R[u] = t;
}
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    f[x] = y;
}
inline int get()
{
    if (!len)
        return 0;
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= len; i++)
        v[b[i]] = 1;
    for (int i = 1; i <= len; i++)
        if (v[d[b[i]]])
            merge(d[b[i]], b[i]);
    for (int i = 1; i <= len; i++)
        cnt += (find(b[i]) == b[i]), upd(res, a[b[i]]);
    for (int i = 1; i <= len; i++)
        v[b[i]] = 0;
    return cnt == 1 ? res : 0;
}
inline int getv(int x)
{
    int p = lower_bound(s.begin(), s.end(), x) - s.begin();
    if (s.empty())
        return 0;
    if (s.back() < x)
        return s.back();
    if (s[0] >= x)
        return 0;
    while (s[p] >= x)
        --p;
    return s[p];
}
inline void sol1(int u, int up)
{
    if (u == up + 1)
        return ans = max(ans, get()), void();
    b[++len] = id[u];
    sol1(u + 1, up);
    b[len--] = 0;
    sol1(u + 1, up);
}
inline void sol2(int u, int up, int op)
{
    if (u == up + 1)
    {
        if (op == 1)
        {
            int val = (get() - a[rt] + mod) % mod;
            if (!get())
                return;
            while (val >= mod)
                val -= mod;
            ans = max(ans, (val + getv(mod - val)) % mod);
        }
        else
            ins(get()), ans = max(ans, get());
        return;
    }
    b[++len] = id[u];
    sol2(u + 1, up, op);
    b[len--] = 0;
    sol2(u + 1, up, op);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> mod;
    for (int i = 2; i <= n; i++)
        cin >> d[i], g[d[i]].push_back(i), g[i].push_back(d[i]);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
        return cout << a[1] % mod, 0;
    dfs(1, 0, 0);
    dfs(rt, 0, 0);
    stable_sort(g[rt].begin(), g[rt].end(), [&](int x, int y)
                { return sz[x] < sz[y]; });
    S[0].push_back(*g[rt].rbegin());
    int sum = 0, val = sz[*g[rt].rbegin()];
    for (int i = 0; i < (int)g[rt].size() - 1; i++)
        sum += sz[g[rt][i]];
    for (int i = 0; i < (int)g[rt].size() - 1; i++)
    {
        if (val + sz[g[rt][i]] <= sum - sz[g[rt][i]])
            sum -= sz[g[rt][i]], val += sz[g[rt][i]], S[0].push_back(g[rt][i]);
        else
            S[1].push_back(g[rt][i]);
    }
    g[rt].clear();
    for (auto v : S[0])
        g[rt].push_back(v);
    for (auto v : S[1])
        g[rt].push_back(v);
    dfs(rt, 0, 1);
    sol1(dfn[rt] + 1, R[*S[0].rbegin()]);
    if (!S[1].empty())
        sol1(dfn[*S[1].begin()], R[*S[1].rbegin()]);
    b[len = 1] = rt;
    sol2(dfn[*S[0].begin()], R[*S[0].rbegin()], 0);
    if (!S[1].empty())
        sol2(dfn[*S[1].begin()], R[*S[1].rbegin()], 1);
    b[len--] = 0;
    cout << ans;
    return 0;
}
