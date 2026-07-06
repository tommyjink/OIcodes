#include <bits/stdc++.h>
#define int long long
using namespace std;

struct O
{
    int t, l, r;
    int x;
} o[105];
int a[105], b[105], c[105], d[105];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i < q; i++)
        {
            cin >> o[i].t;
            if (o[i].t == 1)
                cin >> o[i].l >> o[i].r >> o[i].x;
            else
                cin >> o[i].l >> o[i].r, o[i].x = 0;
        }
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = 1; i <= n; i++)
            c[i] = a[i];
        for (int i = 1; i <= n; i++)
            d[i] = 0;
        for (int i = q - 1; i >= 0; i--)
            if (o[i].t == 1)
                for (int j = o[i].l; j <= o[i].r; j++)
                    d[j] += o[i].x;
        vector<int> v;
        for (int i = 1; i <= n; i++)
            a[i] = c[i];
        for (int i = 0; i < q; i++)
        {
            if (o[i].t == 1)
                for (int j = o[i].l; j <= o[i].r; j++)
                    a[j] += o[i].x;
            else
            {
                int x = -1e18;
                bool f = 0;
                for (int j = o[i].l; j <= o[i].r; j++)
                {
                    int y = b[j] - d[j];
                    if (y > a[j])
                    {
                        if (!f)
                            x = y, f = 1;
                        else if (x != y)
                            ;
                    }
                }
                if (!f)
                {
                    x = 1e18;
                    for (int j = o[i].l; j <= o[i].r; j++)
                        x = min(x, a[j]);
                    if (x > 1e15)
                        x = 0;
                }
                v.push_back(x);
                for (int j = o[i].l; j <= o[i].r; j++)
                    a[j] = max(a[j], x);
            }
            if (o[i].t == 1)
                for (int j = o[i].l; j <= o[i].r; j++)
                    d[j] -= o[i].x;
        }
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');
    }
    return 0;
}