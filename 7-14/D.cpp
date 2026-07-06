#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;
long long fib[N], f[N];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, p;
        cin >> n >> p;
        for (int i = 0; i <= n; ++i)
            fib[i] = f[i] = 0;
        if (n >= 1)
            fib[1] = 1;
        if (n >= 2)
            fib[2] = 1;
        for (int i = 3; i <= n; ++i)
            fib[i] = fib[i - 1] + fib[i - 2];
        for (int i = 1; i <= n; ++i)
            f[i] = f[i - 1] + fib[i] * fib[i];
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            long long x = (i - 2 >= 0) ? f[i - 2] : 0;
            long long y = fib[i] * (x + fib[i] * fib[i] + fib[i]);
            ans += y;
        }
        cout << ans % p << endl;
    }
    return 0;
}