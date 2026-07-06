#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, m, k, a[N];
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        a[i] = 0;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        a[y]++;
    }
    if (n == 1)
    {
        if ((a[2] & 1) && m >= 2)
            cout << "Mimo" << endl;
        else
            cout << "Yuyu" << endl;
        return;
    }
    for (int i = 2; i <= m; i++)
    {
        if (a[i] & 1)
        {
            cout << "Mimo" << endl;
            return;
        }
    }
    cout << "Yuyu" << endl;
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