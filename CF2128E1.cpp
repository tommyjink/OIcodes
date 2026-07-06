#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int t, n, k, a[N], q[N];
int x, y;

bool check(int d) {
    for (int i = 1; i <= n; i++) 
        q[i] = q[i - 1] + (a[i] >= d ? 1 : -1);
    int ps = 0;
    for (int i = k; i <= n; i++) {
        if (q[i - k] < q[ps]) 
            ps = i - k;
        if (q[i] - q[ps] >= 0) {
            x = ps + 1;
            y = i;
            return true;
        }
    }
    return false;
}

void work() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) 
            l = mid;
        else 
            r = mid - 1;
    }
    check(l);
    cout << l << ' ' << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) 
        work();
    return 0;
}