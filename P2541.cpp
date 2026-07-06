#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 10, INF = 2e18;
struct cow
{
    int len, d[20], val;
} p[N];
struct node
{
    int val, i, j;
};
bool operator<(node x, node y) { return x.val > y.val; }
int n, k, ans;
priority_queue<node> q;
bool cmp_cow(cow x, cow y) { return x.val < y.val; }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].len;
        for (int j = 1; j <= p[i].len; j++)
            cin >> p[i].d[j];
        p[i].d[p[i].len + 1] = INF;
        sort(p[i].d + 1, p[i].d + 1 + p[i].len);
        p[i].val = p[i].d[2] - p[i].d[1];
        ans += p[i].d[1];
    }
    sort(p + 1, p + n + 1, cmp_cow);
    q.push({ans - p[1].d[1] + p[1].d[2], 1, 2});
    k--;
    while (!q.empty() && k--)
    {
        node t = q.top();
        q.pop();
        ans += t.val;
        q.push({t.val - p[t.i].d[t.j] + p[t.i].d[t.j + 1], t.i, t.j + 1});
        if (t.i < n)
        {
            q.push({t.val - p[t.i + 1].d[1] + p[t.i + 1].d[2], t.i + 1, 2});
            if (t.j == 2)
                q.push({t.val - p[t.i + 1].d[1] + p[t.i + 1].d[2] - p[t.i].d[2] + p[t.i].d[1], t.i + 1, 2});
        }
    }
    cout << ans << endl;
    return 0;
}