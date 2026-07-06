#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int N = 1e7 + 100;
int n, id[N], l[N], r[N], len;
int tot = 0, head[N], top = 0, stk[N];
int dfn[N], low[N], cnt = 0, num = 0;
int col[N], b[N];
pii a[N];
struct node
{
    int to, next;
} e[N * 2];
void add(int x, int y)
{
    // printf("add(%lld,%lld)\n", x, y);
    e[++tot] = (node){y, head[x]};
    head[x] = tot;
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    stk[top++] = x;
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if (!col[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x])
    {
        cnt++;
        while (1)
        {
            int v = stk[--top];
            col[v] = cnt;
            if (x == v)
                break;
        }
    }
}
bool TwoSAT()
{
    for (int i = 1; i <= 2 * n + id[2 * n]; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (col[i] == col[i + n])
            return false;
    return true;
}
void split(int x, int L, int R)
{
    if (L > R||L>2*n||R>2*n||L<1||R<1)
        return;
    if (id[L] == id[R])
    {
        for (int i = L; i <= R; i++)
            add(x, a[i].second > n ? a[i].second - n : a[i].second + n);
        return;
    }
    for (int i = L; i <= r[id[L]]; i++)
        add(x, (a[i].second > n ? a[i].second - n : a[i].second + n));
    for (int i = id[L] + 1; i <= id[R] - 1; i++)
        add(x, 2 * n + i);
    for (int i = l[id[R]]; i <= R; i++)
        add(x, (a[i].second > n ? a[i].second - n : a[i].second + n));
}
bool check(int mid)
{
    // printf("check(%lld)\n", mid);
    for (int i = 1; i <= 3 * n; i++)
        head[i] = dfn[i] = low[i] = col[i] = 0;
    tot = top = cnt = num = 0;
    for (int i = 1; i <= id[2 * n]; i++)
        for (int j = l[i]; j <= r[i]; j++)
            add(2 * n + i, (a[j].second > n ? a[j].second - n : a[j].second + n));
    for (int i = 1; i <= 2 * n; i++)
    {
        // cout << b[i] << " ";
        int L = lower_bound(b + 1, b + 1 + 2 * n, b[i] - mid+1) - b;
        int R = upper_bound(b + 1, b + 1 + 2 * n, b[i] + mid-1) - b - 1;
        // cout << L << "," << R << "!!" << endl;
        split(a[i].second, L, i-1);
        split(a[i].second, i+1, R);
    }
    // cout << endl;
    return TwoSAT();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    len = sqrt(2 * n);
    for (int i = 1; i <= 2 * n; i++)
    {
        id[i] = (i - 1) / len + 1;
        if (id[i] != id[i - 1])
            r[id[i - 1]] = i - 1, l[id[i]] = i;
    }
    r[id[2 * n]] = 2 * n;
    // for (int i = 1; i <= 2 * n; i++)
    //     cout << id[i] << " ";
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i + n].first;
        a[i].second = i, a[i + n].second = i + n;
    }
    sort(a + 1, a + 1 + 2 * n);
    for (int i = 1; i <= 2 * n; i++)
        b[i] = a[i].first;
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}