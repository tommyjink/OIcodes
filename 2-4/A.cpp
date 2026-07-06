#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 100005;
const int B = 320;

int n, q;
int a[N];
vector<int> num;
vector<int> pos[N];
int id[N], blo[N];
int pre[B + 5][N];
int ha[B + 5][B + 5];

int get_id(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num.push_back(a[i]);
    }
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    
    int m = num.size();
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
        pos[a[i]].push_back(i);
    }
    
    int hc = 0;
    for (int i = 1; i <= m; i++) {
        if (pos[i].size() > B) {
            id[i] = ++hc;
            blo[hc] = i;
        }
    }
    
    for (int i = 1; i <= hc; i++) {
        int val = blo[i];
        for (int j = 1; j <= n; j++) {
            pre[i][j] = pre[i][j - 1] + (a[j] == val);
        }
    }
    
    for (int i = 1; i <= hc; i++) {
        for (int j = 1; j <= hc; j++) {
            int u = blo[i], v = blo[j];
            int cur = 0;
            for (int k = 1; k <= n; k++) {
                if (a[k] == v) ha[i][j] += cur;
                if (a[k] == u) cur++;
            }
        }
    }
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        int idx = lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
        int idy = lower_bound(num.begin(), num.end(), y) - num.begin() + 1;
        
        if (idx > m || num[idx - 1] != x || idy > m || num[idy - 1] != y) {
            cout << 0 << endl;
            continue;
        }
        
        x = idx; y = idy;
        
        if (x == y) {
            int sz = pos[x].size();
            cout << sz * (sz - 1) / 2 << endl;
            continue;
        }
        
        if (id[x] && id[y]) {
            cout << ha[id[x]][id[y]] << endl;
        } else if (id[x]) {
            int ans = 0;
            for (int p : pos[y]) {
                ans += pre[id[x]][p];
            }
            cout << ans << endl;
        } else if (id[y]) {
            int ans = 0, sz = pos[y].size();
            for (int p : pos[x]) {
                ans += sz - pre[id[y]][p];
            }
            cout << ans << endl;
        } else {
            int ans = 0;
            for (int p : pos[x]) {
                ans += pos[y].end() - lower_bound(pos[y].begin(), pos[y].end(), p);
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}