#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
vector<int> G[N];
int fa[N], dep[N], a[N];
vector<int> d;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    fa[1] = 0;
    dep[1] = 0;
    vector<bool> vis(n + 1);
    vis[1] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : G[u])
        {
            if (!vis[v] && v != fa[u])
            {
                vis[v] = 1;
                fa[v] = u;
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            int xx = x, yy = y;
            if (dep[xx] < dep[yy])
                swap(xx, yy);
            while (dep[xx] > dep[yy])
                xx = fa[xx];
            while (xx != yy)
                xx = fa[xx], yy = fa[yy];
            int z = xx;
            vector<int> p;
            for (int t = x; t != z; t = fa[t])
                p.push_back(t);
            p.push_back(z);
            vector<int> ttt;
            for (int t = y; t != z; t = fa[t])
                ttt.push_back(t);
            reverse(ttt.begin(), ttt.end());
            for (int v : ttt)
                p.push_back(v);
            for (int u : p)
                for (int i = 0; i < k; i++)
                    d.push_back(a[u]);
        }
        else if (op == 2)
        {
            int n = d.size();
            if (!n)
                cout << 0 << '\n';
            else
            {
                vector<int> b = d;
                sort(b.begin(), b.end());
                int pos = (n + 1) / 2 - 1;
                cout << b[pos] << '\n';
            }
        }
        else if (op == 3)
        {
            vector<int> b = d;
            d.insert(d.end(), b.begin(), b.end());
        }
    }
    return 0;
}