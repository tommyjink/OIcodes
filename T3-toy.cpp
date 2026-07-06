#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6;
int n, a[N];

bool check(int r) {
    int cnt = 1;
    int last = 1;
    for (int i = 1; i <= n; i++) {
        if ((a[i]-a[last]+1)/2 >r ) {
            cnt++;
            last = i;
        }
    }
    return cnt <= 3;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    int l = 0, r = 1e18;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}