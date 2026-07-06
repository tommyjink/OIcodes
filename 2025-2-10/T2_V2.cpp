#include <bits/stdc++.h>
using namespace std;

#define For(Ti, Ta, Tb) for (int Ti = (Ta); Ti <= (Tb); ++Ti)
#define Dec(Ti, Ta, Tb) for (int Ti = (Ta); Ti >= (Tb); --Ti)
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

int n, m;

int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
ll work(int n, int k) {
    int g = gcd(n, k);
    ll ans = 0;
    int cnt = 0, i = k - 1;

    while (cnt < n / g) {
        int tcnt = (n - i - 1) / k + 1;
        int l = 1, r = tcnt + 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (i + (mid - 1) * k <= cnt + mid) 
                r = mid;
            else 
                l = mid + 1;
        }

        if (l <= tcnt) {
            int st = i + (l - 1) * k, ed = i + (tcnt - 1) * k;
            ans = 1LL * (st + ed) * (tcnt - l + 1) / 2 + (tcnt - l + 1);
        }
        cnt += tcnt;
        i = (i + (tcnt - 1) * k + k) % n;
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        ll ans = -1;
        int ansk = 0;
        For(k, 1, min(n, m)) {
            ll v = work(n, k);
            if (v > ans) ans = v, ansk = k;
        }
        cout << ansk << '\n';
    }
    return 0;
}