#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e3 + 10, M = 1e7 + 10, P = 1e9 + 7;
int n, a[N], b[N], f[N][N], g[N];
int V[N], fac[M], invfac[M], c[M];
int qpow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % P;
        y >>= 1;
        x = x * x % P;
    }
    return res;
}
void init()
{
    invfac[1] = 1;
    // fac[0]=invfac[0]=1;
    // for(int i=1;i<M;i++)
    //     fac[i]=fac[i-1]*i%P;
    // invfac[M-1]=qpow(fac[M-1],P-2);
    // for(int i=M-2;i>=1;i--)
    //     invfac[i]=invfac[i+1]*(i+1)%P;
    for (int i = 2; i <= n; ++i)
        invfac[i] = (P - P / i) * invfac[P % i] % P;
}
inline int comb(int x, int y)
{
    return fac[x] * invfac[y] % P * invfac[x - y] % P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i],
            V[++V[0]] = b[i] + 1,
            V[++V[0]] = a[i];
    sort(V + 1, V + 1 + V[0]);
    V[0] = unique(V + 1, V + 1 + V[0]) - V - 1;
    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(V + 1, V + 1 + V[0], b[i] + 1) - V,
        a[i] = lower_bound(V + 1, V + 1 + V[0], a[i]) - V;
    c[0] = g[0] = 1;
    for (int j = 1; j < V[0]; j++)
    {
        int len = V[j + 1] - V[j];
        for (int i = 1; i <= n; i++)
            c[i] = c[i - 1] * (i + len - 1) % P * invfac[i] % P;
        for (int i = n; i >= 0; i--)
        {
            if (a[i] <= j && j < b[i])
            {
                int now = len, f = 0, m = 1;
                for (int k = i - 1; k >= 0; k--)
                {
                    f = (f + now * g[k] % P) % P;
                    if (a[k] <= j && j < b[k])
                        now = c[++m];
                }
                g[i] = (g[i] + f) % P;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + g[i]) % P;
    cout << ans << endl;
    return 0;
}