#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], maxm = 0,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    a[n + 1] = m;
    if (a[1] != 1)
    {
        cout << "No answer!!!";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        while (maxm+1 < a[i + 1])
        {
            maxm+=a[i],ans++;
            if(maxm>=m)
            {
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<ans+1;
    return 0;
}