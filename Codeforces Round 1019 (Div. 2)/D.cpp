#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N];
vector<int> v[N];
void solve()
{
    int n, m = 0;
    cin >> n;
    int p = 0, l = 0, r = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i], m = max(m, a[i]);
        if (a[i] == -1)
            p = i;
        else
            v[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (i & 1)
        {
            for (int j = 0; j < (int)v[i].size() && v[i][j] < p; j++)
                b[v[i][j]] = --r;
            for (int j = (int)v[i].size()-1; j >=0 && v[i][j] > p; j--)
                b[v[i][j]] = --r;
        }
        else
        {
            for (int j = 0; j < (int)v[i].size() && v[i][j] < p; j++)
                b[v[i][j]] = ++l;
            for (int j = (int)v[i].size()-1; j >=0 && v[i][j] > p; j--)
                b[v[i][j]] = ++l;
        }
    }
    b[p]=++l;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    for(int i=1;i<=m;i++)
        v[i].clear();
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
5
-1 1 2 1 2


3  4 2 5 1
4 5 2 3 1


7
3
1 1 -1
5
1 -1 1 2 1
8
3 1 2 1 -1 1 1 2
7
1 1 1 -1 1 1 1
5
1 1 1 1 -1
5
-1 1 1 1 1
5
-1 1 2 1 2

*/