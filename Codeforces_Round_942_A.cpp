#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000000;
int a[N];

signed main()
{
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        int n, k;
        scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        sort(a + 1, a + 1 + n);
        int mina = a[1], kk = k, i, hv = 0;
        for (i = 2; i <= n; i++)
        {
            if (kk >= (a[i] - mina) * (i - 1))
            {
                kk -= (a[i] - mina) * (i - 1);
                mina = a[i];
            }
            else
            {
                int x = kk / (i - 1), mo = kk % (i - 1);
                mina += x;
                hv += mo;
                break;
            }
        }
        if (kk&&(i==n+1||n==1))
        {
            int x = kk / n;
            mina += x;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] - mina > 0)
                hv++;
        }
        // printf("%lld ", mina);
        printf("%lld\n", (mina - 1) * n + 1 + hv);
    }
    return 0;
}