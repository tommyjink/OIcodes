#include <bits/stdc++.h>
#define int long long
#define lowbit(x) x & (-x)
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, t[N];
struct node
{
    int val, num;
} a[N], b[N];
bool cmp(node x, node y)
{
    return x.val < y.val;
}
void add(int x, int d)
{
    for (int i = x; i <= n; i += lowbit(i))
        t[i] += d;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += t[i];
    return res;
}
void solve()
{
    cin >> n;
    int aa = 0, bb = 0, ca = 0, cb = 0;
    set<int> sa, sb;
    for (int i = 1; i <= n; i++)
        if (i & 1)
            cin >> a[++aa].val, a[aa].num = aa;
        else
            cin >> b[++bb].val, b[bb].num = bb;
    sort(a + 1, a + 1 + aa, cmp);
    sort(b + 1, b + 1 + bb, cmp);
    for (int i = 1; i <= aa; i++)
        t[i] = 0;
    for (int i = 1; i <= aa; i++)
        add(i, 1);
    for (int i = 1; i <= aa; i++)
        add(a[i].num, -1), ca += query(a[i].num);

    for (int i = 1; i <= bb; i++)
        t[i] = 0;
    for (int i = 1; i <= bb; i++)
        add(i, 1);
    for (int i = 1; i <= bb; i++)
        add(b[i].num, -1), cb += query(b[i].num);
    vector<int> ans;
    aa = 0, bb = 0;
    for (int i = 1; i <= n; i++)
        if (i & 1)
            ans.push_back(a[++aa].val);
        else
            ans.push_back(b[++bb].val);
    if (abs(ca - cb) % 2 == 1)
        swap(ans[n-1],ans[n-3]);
    // cout<<ca<<"!!"<<cb<<endl;
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
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
3 4 2 1
1 3 4 2(3)
1 2 3 4(2)
3+1+2+2


3
4
3 4 1 2
5
5 4 3 1 2
10
10 9 8 7 6 5 4 3 2 1

*/