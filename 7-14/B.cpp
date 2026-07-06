#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], ans = 0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += (m / (a[i] * a[j]));
    cout << ans << endl;
    return 0;
}