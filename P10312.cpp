#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 100, H = 15;
int h, n, k = 1, j = 0, a[H][N], cnt = -1;
string s, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> s;
    n = s.length();
    for (int i = 1; i <= n; i++)
    {
        j += k;
        if (j == h || (j == 1 && i != 1))
            k = -k;
        a[j][i] = 1;
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[i][j])
                a[i][j] = (int)s[++cnt];
    }
    j=0,k=1;
    for (int i = 1; i <= n; i++)
    {
        j += k;
        if (j == h || (j == 1 && i != 1))
            k = -k;
        ans.push_back((char)a[j][i]);
    }
    cout << ans << endl;
    return 0;
}