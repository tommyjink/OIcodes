#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef unsigned int uint;
inline uint get_next(uint &seed)
{
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}
const int N = 1e7 + 10;
uint seed;
long long n, a[N], ans,fa[N];
vector<int> e[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> seed;
    for (int i = 1; i <= n; i++)
        a[i] = get_next(seed);
    ans=a[1];
    for (int i = 2; i <= n; i++)
    {
        fa[i] = get_next(seed) % (i - 1) + 1;
        a[i]=min(a[i],a[fa[i]]);
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}