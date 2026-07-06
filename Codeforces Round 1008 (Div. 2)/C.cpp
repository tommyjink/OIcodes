#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n * 2);
        for (int &i : a) cin >> i;
        sort(a.begin(), a.end());
        int s1 = 0, s0 = 0;
        for (int i = 0; i < n * 2; i += 2) {
            swap(a[i], a[i + 1]);
            s1 += a[i];
            s0 += a[i + 1];
        }
        s1 += a[n * 2 - 1];
        s0 -= a[n * 2 - 1];
        a.push_back(s1 - s0);
        swap(a[n * 2], a[n * 2 - 1]);
        for (int i : a)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}