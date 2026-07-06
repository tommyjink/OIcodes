#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 300000 + 10;
const int INF = 1e18;

int n, q;
vector<pair<int, int>> g[N];
int sz[N], son[N], fa[N], dep[N], top[N], dfn[N], tot, fval[N];
int tr[N], cnt, tag[N];

void dfs1(int u, int f)
{
    fa[u] = f;
    sz[u] = 1;
    for (auto t : g[u])
    {
        int v = t.first, w = t.second;
        if (v == f)
            continue;
        fval[v] = w;
        dep[v] = dep[u] + w;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
            son[u] = v;
    }
}

// void dfs2(int u)
// {
//     dfn[u] = ++tot;
//     if (son[u])
//     {
//         top[son[u]] = top[u];
//         dfs2(son[u]);
//     }
//     for (auto t : g[u])
//     {
//         int v = t.first;
//         if (v == fa[u] || v == son[u])
//             continue;
//         top[v] = v;
//         dfs2(v);
//     }
// }
void dfs2(int u)
{
    dfn[u] = ++tot;
    if (son[u])
    {
        top[son[u]] = top[u];
        dfs2(son[u]);
    }
    for (auto t : g[u])
    {
        int v = t.first;
        if (v == fa[u] || v == son[u])
            continue;
        top[v] = v;
        dfs2(v);
    }
}
inline void add(int p, int v)
{
    while (p <= n)
    {
        tr[p] += v;
        p += p & -p;
    }
}

inline int askbit(int p)
{
    int ans = 0;
    while (p)
    {
        ans += tr[p];
        p -= p & -p;
    }
    return ans;
}

struct Segment
{
    struct node
    {
        int l, r, mn;
    } t[N * 4];
    int lazy[N * 4];

    inline void pushup(int k)
    {
        t[k].mn = min(t[k * 2].mn, t[k * 2 + 1].mn);
    }

    inline void pushdown(int k)
    {
        if (!lazy[k])
            return;
        t[k * 2].mn += lazy[k];
        t[k * 2 + 1].mn += lazy[k];
        lazy[k * 2] += lazy[k];
        lazy[k * 2 + 1] += lazy[k];
        lazy[k] = 0;
    }

    void build(int k, int l, int r, int val)
    {
        t[k].l = l, t[k].r = r, t[k].mn = val;
        lazy[k] = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(k * 2, l, mid, val);
        build(k * 2 + 1, mid + 1, r, val);
        pushup(k);
    }

    void modify(int k, int x, int d)
    {
        if (t[k].l == t[k].r)
        {
            t[k].mn = d;
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) >> 1;
        if (x <= mid)
            modify(k * 2, x, d);
        else
            modify(k * 2 + 1, x, d);
        pushup(k);
    }

    void update(int k, int l, int r, int d)
    {
        if (t[k].l > r || t[k].r < l)
            return;
        if (l <= t[k].l && t[k].r <= r)
        {
            t[k].mn += d;
            lazy[k] += d;
            return;
        }
        pushdown(k);
        update(k * 2, l, r, d);
        update(k * 2 + 1, l, r, d);
        pushup(k);
    }

    int query(int k, int l, int r)
    {
        if (t[k].l > r || t[k].r < l)
            return INF;
        if (l <= t[k].l && t[k].r <= r)
            return t[k].mn;
        pushdown(k);
        return min(query(k * 2, l, r), query(k * 2 + 1, l, r));
    }
} s1, s2;

inline int cdep(int u)
{
    return dep[u] + askbit(dfn[u]);
}

inline int calc(int u, int ban)
{
    if (ban == 0)
        return s1.query(1, dfn[u], dfn[u] + sz[u] - 1) - cdep(u);
    return min(s1.query(1, dfn[u], dfn[ban] - 1), s1.query(1, dfn[ban] + sz[ban], dfn[u] + sz[u] - 1)) - cdep(u);
}

int ask(int u)
{
    // cout<<u<<"!!!"<<endl;
    if (!cnt)
        return -1;
    int ans = calc(u, 0), v = cdep(u);
    while (u)
    {
        ans = min(ans, s2.query(1, dfn[top[u]], dfn[u]) + v);
        u = top[u];
        if (u != 1)
        {
            ans = min(ans, calc(fa[u], u) + v - cdep(fa[u]));
            u = fa[u];
        }
        else
            break;
    }
    return ans;
}

void renew(int u)
{
    if (!u)
        return;
    s2.modify(1, dfn[u], calc(u, son[u]) - cdep(u));
    renew(fa[top[u]]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin>>n;
    // s1.build(1,1,n,0);
    // while(1)
    // {
    //     int op,l,r,x,d;
    //     cin>>op;
    //     if(op==1)
    //     {
    //         cin>>x>>d;
    //         s1.modify(1,x,d);
    //     }
    //     else if(op==2)
    //     {
    //         cin>>l>>r>>d;
    //         s1.update(1,l,r,d);
    //     }
    //     else if(op==3)
    //     {
    //         cin>>l>>r;
    //         cout<<s1.query(1,l,r)<<endl;
    //     }
    //     else
    //     {
    //         for(int i=1;i<=n;i++)
    //             cout<<s1.query(1,i,i)<<" ";
    //         cout<<endl;
    //     }
    // }
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs1(1, 0);
    top[1] = 1;
    dfs2(1);

    s1.build(1, 1, n, INF);
    s2.build(1, 1, n, INF);

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int u;
            cin >> u;
            cout << ask(u) << endl;
        }
        else if (op == 2)
        {
            int u;
            cin >> u;
            if (tag[u])
            {
                cnt--;
                tag[u] = 0;
                s1.modify(1, dfn[u], INF);
            }
            else
            {
                cnt++;
                tag[u] = 1;
                s1.modify(1, dfn[u], cdep(u));
            }
            renew(u);
        }
        else
        {
            int a, b, w;
            cin >> a >> b >> w;
            if (fa[a] == b)
                swap(a, b);
            s2.update(1, dfn[b], dfn[b] + sz[b] - 1, fval[b] - w);
            add(dfn[b], w - fval[b]);
            add(dfn[b] + sz[b], fval[b] - w);
            s1.update(1, dfn[b], dfn[b] + sz[b] - 1, w - fval[b]);
            fval[b] = w;
            renew(a);
        }
    }
    return 0;
}
