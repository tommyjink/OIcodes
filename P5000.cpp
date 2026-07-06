#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e3;
int T, R;
struct node
{
    int a[N], len;
    node()
    {
        memset(a, 0, sizeof(a));
        len = 0;
    }
};
node operator+(node x, node y)
{
    int tag = 0;
    if (x.len < y.len)
        swap(x, y);
    for (int i = 1; i <= x.len; i++)
    {
        x.a[i] += y.a[i] + tag;
        tag = x.a[i] / 10;
        x.a[i] %= 10;
    }
    if (tag)
        x.a[++x.len] = 1;
    return x;
}
node operator*(node x, int y)
{
    int tag = 0;
    for (int i = 1; i <= x.len; i++)
    {
        x.a[i] = x.a[i] * y + tag;
        tag = x.a[i] / 10;
        x.a[i] %= 10;
    }
    while (tag)
    {
        x.a[++x.len]=tag%10;
        tag/=10;
    }
    return x;
}
void scan(node &x)
{
    string s;
    cin >> s;
    x.len = s.length();
    for (int i = 1; i <= x.len; i++)
        x.a[i] = s[x.len - i] - '0';
}
void print(node x)
{
    for (int i = x.len; i >= 1; i--)
        cout << x.a[i];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> R;
    R %= 26;
    while (T--)
    {
        string s;
        node res;
        res.a[1] = 1;
        res.len = 1;
        cin >> s;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            s[i] += R;
            if (s[i] > 'Z')
                s[i] -= 26;
            res = res * (int)s[i];
            // print(res);cout<<endl;
        }
        cout << s << endl;
        print(res);
        cout << endl;
    }
    return 0;
}