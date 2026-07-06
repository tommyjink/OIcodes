#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 50;
int n, k, h[N], g[N], ans = 0;
vector<int> a[N], b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i] >> g[i];
    for (int i = 1; i < (1ll << (n / 2)); i++)
    {
        int ed = 0, cnt = 0, l = 0, tag = true;
        for (int j = 1; j <= n / 2; j++)
        {
            if (i & (1ll << (j - 1)))
            {
                if (h[j] < l)
                {
                    tag = false;
                    break;
                }
                cnt += g[j];
                ed = j;
                l = h[j];
            }
        }
        if (!tag)
            continue;
        a[ed].push_back(cnt);
        if (cnt >= k)
            ans++;
        // cout<<st<<"!"<<cnt<<endl;
    }
    for (int i = 0; i < (1ll << (n - n / 2)); i++)
    {
        int st = 0, cnt = 0, l = 0, tag = true;
        for (int j = 1; j <= n - n / 2; j++)
        {
            if (i & (1ll << (j - 1)))
            {
                if (h[j + n / 2] < l)
                {
                    tag = false;
                    break;
                }
                cnt += g[j + n / 2];
                if (!st)
                    st = j + n / 2;
                l = h[j + n / 2];
            }
        }
        if (!tag)
            continue;
        b[st].push_back(cnt);
        if (cnt >= k)
            ans++;
    }
    for (int i = 1; i <= n / 2; i++)
        sort(a[i].begin(), a[i].end());
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = n / 2 + 1; j <= n; j++)
        {
            if (h[i] <= h[j])
            {
                for (auto v : b[j])
                {
                    int p = lower_bound(a[i].begin(), a[i].end(), k - v) - a[i].begin();
                    ans += a[i].size() - p;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
4 6
2 1
6 3
7 2
5 6
*/