#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e3 + 10;
int n, a[N][N], cnt = 0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= n / 2; j++)
        {
            a[i][j] = 0+cnt,
            a[i][j + n / 2] = 1+cnt,
            a[i + n / 2][j] = 2+cnt,
            a[i + n / 2][j + n / 2]=3+cnt;
            cnt+=4;
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}