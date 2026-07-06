#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6;
int len = 0, a[N], l[N], r[N], bg = 0, ed = 0, tot = 0, p = 0;
void push_front(int x)
{
    a[++tot] = x;
    l[bg] = tot;
    r[tot] = bg;
    bg = tot;
}
void push_back(int x)
{
    a[++tot] = x;
    r[ed] = tot;
    l[tot] = ed;
    ed = tot;
}
void del(int x)
{
    int ll = l[x], rr = r[x];
    r[ll] = rr;
    l[rr] = ll;
    l[x] = r[x] = 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            len++;
            if (len == 1)
            {
                a[++tot] = x;
                bg = ed = p = tot;
            }
            else
            {
                push_front(x);
                if (len % 2 == 0)
                    p = l[p];
            }
        }
        if (op == 2)
        {
            int x;
            cin >> x;
            len++;
            if (len == 1)
            {
                a[++tot] = x;
                bg = ed = p = tot;
            }
            else
            {
                push_back(x);
                if (len % 2 == 1)
                    p = r[p];
            }
        }
        if (op == 3)
        {
            len--;
            int ll = l[p], rr = r[p];
            cout << a[p] << endl;
            del(p);
            if (len == 0)
                p = 0;
            else if (len % 2 == 1)
                p = rr;
            else
                p = ll;
        }
    }
    return 0;
}