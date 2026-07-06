#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e6 + 100;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        if (n > 65)
            cout << "0\n";
        else
        {
            unsigned long long res = 1;
            for (int i = 1; i <= n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    res *= (a[i] ^ a[j]);
            cout << res << '\n';
        }
    }
    return 0;
}
