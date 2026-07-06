#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int n, k, tot, t, vis[N];
vector<int> v[N];
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    t = (n - 1) / 2;
    if (n % 2 == 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << t << '\n';
    tot = gcd(n, k);
    for (int i = 0; i < tot; ++i)
    {
        int x = i;
        while (!vis[x])
        {
            v[i % tot].push_back(x);
            vis[x] = 1;
            x = (x + k) % n;
        }
    }
    for (int i = 1; i < tot; ++i)
    {
        for (int j = 1; j < n / tot; j += 2)
        {
            cout << v[i - 1][j - 1] << ' ' << v[i][j] << '\n';
            --t;
        }
    }
    int y = 0;
    while (y < tot)
    {
        for (int i = 1; i < n / tot; i += 2)
        {
            cout << v[y][i - 1] << ' ' << v[y][i] << '\n';
            --t;
        }
        y += n / tot - 1;
    }
    for (int i = 1; i < n / tot; i += 2)
    {
        if (!t)
            break;
        --t;
        cout << v[tot - 1][i - 1] << ' ' << v[tot - 1][i] << '\n';
    }
    return 0;
}