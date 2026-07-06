#include <bits/stdc++.h>
#include "inv.h"
const int N = (1 << 21) + 5;
const int mod = 998244353;
const int B = 1024;
int pl[N], iv[N];
void init(int p)
{
    const int n = B * B+1;
    iv[1] = 1;
    for (int i = 2; i <= n; i++)
        iv[i] = 1ll * (mod - iv[mod % i]) * (mod / i) % mod;
    for (int i = 1; i <= B; i++)
    {
        int x = 0;
        while (x <= B * B)
        {
            long long w = 1ll * x * B * i % mod;
            if (w <= B * B || w >= mod - B * B)
                pl[x] = i, x++;
            else
                x += (mod - B * B - w + B * i - 1) / (B * i);
        }
    }
}
int inv(int x)
{
    long long w = 1ll * x * pl[x >> 10] % mod;
    if (w <= 2 * B * B)
        return 1ll * iv[w] * pl[x / B] % mod;
    else
        return 1ll * (mod - iv[mod - w]) * pl[x / B] % mod;
}