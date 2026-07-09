#include <bits/stdc++.h>
using namespace std;

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    if (res == -1)
        exit(0);
    return res;
}
void report(int x)
{
    cout << "! " << x << endl;
}
void solve()
{
    int n;
    cin >> n;

    int l = 1, r = n;

    int p = query(l, r);

    while (true)
    {
        int m = r - l + 1;

        if (m == 2)
        {
            report(p == l ? r : l);
            return;
        }

        int k = max((m + 1) / 2, (int)(m * 0.618));
        int al, ar, bl, br;
        if (p <= l + k - 1)
        {
            al = l;
            ar = l + k - 1;
            bl = ar + 1;
            br = r;
        }
        else
        {
            al = r - k + 1;
            ar = r;
            bl = l;
            br = al - 1;
        }
        int q = query(al, ar);
        if (q == p)
        {
            l = al;
            r = ar;
        }
        else
        {
            l = bl;
            r = br;
            if (l == r)
            {
                report(l);
                return;
            }
            p = query(l, r);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}