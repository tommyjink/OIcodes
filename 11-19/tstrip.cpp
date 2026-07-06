#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int N = 110, INF = 1e16;
int n, m, d[N], use[N], cnt[N];
int head[N], tot = 0;
struct node
{
    int from, to, next, val;
} E[N * 2];
void add(int x, int y, int z)
{
    E[++tot] = (node){x, y, head[x], z};
    head[x] = tot;
}
bool SPFA(int mid)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        d[i] = INF, use[i] = 0, cnt[i] = 0;
    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        use[x] = false;
        for (int i = head[x]; i != 0; i = E[i].next)
        {
            int y = E[i].to;
            if (d[y] > d[x] + E[i].val+mid)
            {
                d[y] = d[x] + E[i].val+mid;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] > n)
                    return false;
                if (use[y] == false)
                {
                    use[y] = true;
                    q.push(y);
                }
            }
        }
    }
    if(d[n]<0)return false;
    return true;
}
void solve()
{
    cin >> n >> m;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=0;
    for (int i = 1; i <= m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    int l = 0, r = 2e5;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (SPFA(mid-1e5))
            r = mid;
        else
            l = mid + 1;
    }
    SPFA(l-1e5);
    if (d[n] > 1e9)
        cout << "-1" << endl;
    else
        cout << d[n] << endl;
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
/*


输入
1
4 5
1 2 1
1 3 1
2 3 -3
3 1 1
3 4 1

输出
2



输入
1
4 6
1 2 -3
2 3 2
3 1 1
1 3 -1
4 3 -1
3 4 -1000

输出

1
3 2
1 2 100
2 3 99


*/