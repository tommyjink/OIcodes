#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int P = 998244353;
const int N = 3e5 + 100;

int n;
int fac[N], ifac[N];
int cnt[N];
map<int,int> a[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}
int F(int x)
{
    return qpow(x,P-2);
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % P;
    ifac[N - 1] = qpow(fac[N - 1], P - 2);
    for (int i = N - 2; i >= 0; --i)
        ifac[i] = ifac[i + 1] * (i + 1) % P;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int d;
        cin >> d;
        map<int, int> mp;
        for (int j = 1; j <= d; ++j)
        {
            int x;
            cin >> x;
            mp[x]++;
            cnt[x]++;
        }
        a[i] = mp;
    }

    int ans = 1;
    int half = (n+1) / 2;
    for (int k = 1; k < half; ++k)
        ans = ans * fac[cnt[k]] % P;

    if (n % 2 == 0)
    {
        int x = cnt[half];
        int res = fac[x];
        res = res * qpow(qpow(2, x / 2), P - 2) % P;
        res = res * ifac[x / 2] % P;
        ans = ans * res % P;
    }

    int div = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (auto &p : a[i])
            div = div * ifac[p.second] % P;
    }
    // cout<<ans<<" "<<F(div)<<endl;
    ans = ans * div % P;

    cout << ans << endl;
    return 0;
}