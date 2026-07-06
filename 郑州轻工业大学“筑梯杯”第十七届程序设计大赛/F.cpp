#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5;
int n;
int head[N], tot = 0;
struct node1
{
    int from, to, next;
} e[N * 2];
void add(int x, int y)
{
    e[++tot] = (node1){x, y, head[x]};
    head[x] = tot;
}
struct node
{
    int u, v, val;
} ee[N];
bool cmp(node x, node y)
{
    return x.val > y.val;
}
void solve()
{
    memset(head, 0, sizeof(head));
    tot = 0;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> ee[i].u >> ee[i].v >> ee[i].val;
        add(ee[i].u, ee[i].v);
        add(ee[i].v, ee[i].u);
    }
    sort(ee + 1, ee + 1 + n - 1, cmp);
    int x = ee[1].u, y = ee[1].v;
    // cout<<x<<"@#!"<<y<<endl;
    int tt = 0;
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        // cout<<v<<"~~~"<<endl;
        if (v == y)
            continue;
        tt = v;
        break;
    }
    if (tt)
    {
        cout << tt << " " << y << " 0" << endl;
        return;
    }
    for (int i = head[y]; i; i = e[i].next)
    {
        int v = e[i].to;
        // cout<<v<<"~~~"<<endl;
        if (v == x)
            continue;
        tt = v;
        break;
    }
    cout << tt << " " << x << " 0" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}