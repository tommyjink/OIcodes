#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int ans = 0;
int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}
void dfs(int x, int y, int step)
{
    if (step > ans)
        return;
    if (x == 0 && y == 0)
    {
        ans = min(ans, step);
        return;
    }
    if (x)
        dfs(x - gcd(x, y), y, step + 1);
    if (y)
        dfs(x, y - gcd(x, y), step + 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        ans = 1e15;
        dfs(x, y, 0);
        cout << ans << endl;
    }
    return 0;
}
/*
3
3 4
12 20

5
345 78781231243213
321 1231231231231
12 12312312322222
4799 9729719
4859 1552318
*/