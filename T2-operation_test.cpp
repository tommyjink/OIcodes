#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 100000000;
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int lcm(int x, int y)
{
    return (x / gcd(x, y)) * y;
}
int l[N + 100], r[N + 100];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= N; i++)
    {
        int tmp = 1;
        for (int j = i; j <= N; j++)
        {
            tmp = lcm(tmp, j);
            if (tmp > N)
                break;
            if (!l[tmp])
                l[tmp] = i, r[tmp] = j;
        }
    }
    for (int j = 3; j <= 10; j++)
    {
        cout<<"____________________"<<j<<"________________"<<endl;
        for (int i = 1; i <= N; i++)
            if (l[i] + j == r[i])
                cout << i << ":" << l[i] << " " << r[i] << endl;
    }
    return 0;
}