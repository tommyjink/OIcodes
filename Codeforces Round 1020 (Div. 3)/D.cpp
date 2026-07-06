#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6;
int n, m;
int a[N], b[N], c[N], d[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int j = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] >= b[j])
        {
            c[j] = i;
            j++;
            if (j > m)
            {
                cout << "0" << endl;
                return;
            }
        }
    j = m;
    for (int i = n; i >= 1; i--)
        if (a[i] >= b[j])
            d[j] = i, j--;
    if(m==1)
    {
        cout<<b[1]<<endl;
        return;
    }
    int ans = 1e15;
    if (c[m - 1])
        ans = min(ans, b[m]);
    if (d[2])
        ans = min(ans, b[1]);
    for (int i = 1; i <= m - 2; i++)
        if (c[i] && d[i + 2] && c[i] < d[i + 2])
            ans = min(ans, b[i + 1]);
    if (ans == 1e15)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        solve();
        for (int i = 1; i <= n; i++)
            a[i] = b[i] = c[i] = d[i] = 0;
    }
    return 0;
}
/*
7
9 5
3 5 2 3 3 5 8 1 2
4 6 2 4 6
6 3
1 2 6 8 2 1
5 4 3
5 3
4 3 5 4 3
7 4 5
6 3
8 4 2 1 2 5
6 1 4
5 5
1 2 3 4 5
5 4 3 2 1
6 3
1 2 3 4 5 6
9 8 7
5 5
7 7 6 7 7
7 7 7 7 7

*/