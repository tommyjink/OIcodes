#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 100;
int n, m, in[N], vis[N];
int head[N], tot = 0, cnt = 0;
struct node
{
    int from, to, next;
} e[N * 2];
void add(int x, int y)
{
    e[++tot] = (node){x, y, head[x]};
    head[x] = tot;
}
priority_queue<int> q;
vector<int> a;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        in[i] = head[i] = 0;
    tot = cnt = 0;
    a.clear();
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(y, x);
        in[x]++;
    }
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int t = q.top();
        q.pop();
        cnt++;
        a.push_back(t);
        for (int i = head[t]; i; i = e[i].next)
        {
            int v = e[i].to;
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }
    if (cnt < n)
        cout << "Impossible! " << endl;
    else
    {
        for (int i=a.size()-1;i>=0;i--)
            cout << a[i] << " ";
        cout << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}    