#include <bits/stdc++.h>
using namespace std;
int n, a[20], b[20], mx = -1, ans = -1;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> S(n);
        for (int i = 0; i < n; i++)
            S[i] = (mask & (1 << i)) ? b[i] : a[i];
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int l = (i == 0) ? 0 : S[i - 1], r = (i == n - 1) ? 0 : S[i + 1];
            if (S[i] > l && S[i] > r)
                cnt++;
        }
        int mxv = S[0], mnv = S[0];
        for (int x : S)
            mxv = max(mxv, x), mnv = min(mnv, x);
        int d = mxv - mnv;
        if (cnt > mx)
            mx = cnt, ans = d;
        else if (cnt == mx)
            ans = max(ans, d);
    }
    cout << mx << '\n'
         << ans << '\n';
    return 0;
}