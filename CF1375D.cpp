#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010], b[2010], vis[1010];
signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			vis[a[i]]++; 
		}
		int ans = 0;  
		while (1) {
			int mex = 0;
			for (int i = 0; i <= n; i++) {  
				if (!vis[i]) {
					mex = i;
					break;
				}
			}
			if (mex != n) {
				vis[a[mex + 1]]--;
				b[++ans] = mex + 1;
				a[mex + 1] = mex;
				vis[mex]++;
			} else {
                bool f = 0;
				for (int i = 1; i <= n; i++) {
					if (a[i] != i - 1) {
                        f = 1;
						vis[a[i]]--;
						a[i] = mex;
						vis[mex]++;
						b[++ans] = i;
						break;
					}
				}
                if (!f)  
                    break;
			}
		}
		cout << ans << endl;
		for (int i = 1; i <= ans; i++)
			cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}
