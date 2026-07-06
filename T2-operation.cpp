#include <bits/stdc++.h>
#define int __int128
#define endl "\n"
using namespace std;
const int INF = 1e18 + 100;
__int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        f = -1, ch = getchar();
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f * x;
}
void print(__int128 x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int lcm(int x, int y)
{
    if (x / gcd(x, y) * y > INF)
        return INF;
    return (x / gcd(x, y)) * y;
}
int f(int x, int y)
{
    int res = 1;
    for (int i = x; i <= y; i++)
        res = lcm(res, i);
    return res;
}
int cal(int x, int y)
{
    int l = 1, r = x - y + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int res = f(mid, mid + y - 1);
        if (res < x)
            l = mid + 1;
        else
            r = mid;
    }
    for (int i = l - 1000; i <= l + 1000; i++)
        if (f(i, i + y - 1) == x)
            return i;
    return 0;
}
signed main()
{
    freopen("operation.in", "r", stdin);
    freopen("operation.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << f(6, 9) << endl;
    int T;
    T = read();
    while (T--)
    {
        int x, ans = INF, ans1 = 0, i;
        x = read();
        for (i = 20; i >= 1; i--)
        {
            int res = cal(x, i);
            if (!res)
                continue;
            if (res < ans)
                ans = res, ans1 = i;
            else if (res == ans)
                ans1 = i;
        }
        print(ans);
        cout << " ";
        print(ans + ans1 - 1);
        cout << endl;
    }
    return 0;
}
/*
4
6
9
504
99999990000000


1 3
9 9
6 9
9999999 10000000
*/