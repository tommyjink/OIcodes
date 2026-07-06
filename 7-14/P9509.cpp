#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e3 + 10, M = 3e6;
int n, a[N];
bitset<M> f1, f2;
void solve()
{
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], m += a[i];
    if (m % n)
    {
        cout << "No" << endl;
        return;
    }
    int p = m / n;
    for (int i = 1; i <= n; i++)
        a[i] -= p;
    f1 = f2 = 0;
    f1[0] = f2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
            f1 |= (f1 << a[i]);
        else if (a[i] < 0)
            f2 |= (f2 << (-a[i]));
        else
        {
            cout << "Yes" << endl;
            return;
        }
    }
    if ((f1 & f2).count() <= 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return;
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
4
5
1 1 1 1 1
5
1 2 3 4 5
5
1 1 1 1 6
5
-1 0 1 0 1
*/