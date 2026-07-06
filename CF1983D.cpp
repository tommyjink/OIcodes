#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int t[N], n, a[N], b[N];

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int d)
{
    for (int i = x; i <= N; i += lowbit(i))
        t[i] += d;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += t[i];
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int aa = 0, bb = 0, ans = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            add(a[i], 1);
            aa += i - query(a[i]);
        }
        for (int i = 1; i <= n; i++)
            add(a[i], -1);
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            add(b[i], 1);
            bb += i - query(b[i]);
        }
        for (int i = 1; i <= n; i++)
            add(b[i], -1);
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; i++)
            if (a[i] != b[i])
                ans = false;
        if (aa % 2 == bb % 2 && ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
1 
4 
37122 30915 5098 13035 
30915 37122 13035 5098
*/