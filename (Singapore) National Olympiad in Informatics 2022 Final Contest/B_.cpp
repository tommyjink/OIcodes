#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 500000 + 10;
int n, x[N], l[N], sum;
pair<int, int> a[N];
priority_queue<int> q;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    for (int i = 1; i <= n; i++)
        a[i] = {l[i] + x[i], x[i]};
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        q.push(a[i].second);
        sum += a[i].second;
        if (sum > a[i].first)
        {
            sum -= q.top();
            q.pop();
        }
    }
    cout << q.size() << endl;
    return 0;
}
