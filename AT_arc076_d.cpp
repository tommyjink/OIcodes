#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 10;
int n, m;
pii a[N];
bool cmp(pii x, pii y)
{
    if (x.first != y.first)
        return x.first < y.first;
    return x.second > y.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, cmp);
    int ll = 1, rr = m, ans = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i].second);
        if (ll <= rr && ll <= a[i].first) ll++;
        else
        {
            tmp.push_back(q.top());
            q.pop();
        }
    }
    sort(tmp.begin(), tmp.end(), greater<int>());
    for (int r : tmp)
    {
        if (ll <= rr && rr >= r)rr--;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}