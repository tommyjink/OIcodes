#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, a[2000005], b[2000005], now;
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	sort(a + 1, a + n + 1);
	if (n == 2) {
		int d = a[2] - a[1];
		if (d == 0) {
			if (b[2] == b[1] && b[1] == a[2]) cout << "YES\n";
			else cout << "NO\n";
			return ;
		}
		sort(b + 1, b + n + 1);
		if (b[2] - b[1] == d && (b[2] - a[2]) % d == 0 && (b[1] - a[1]) % d == 0) cout << "YES\n";
		else cout << "NO\n";
		return ;
	}
	now = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) continue;
		if (now) now = gcd(now, 2 * (a[i] - a[i - 1]));
		else now = 2 * (a[i] - a[i - 1]);
	}
	if (!now) {
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) {
			if (a[i] != b[i]) {
				cout << "NO\n";
				return ;
			}
		}
		cout << "YES\n";
		return ;
	}
	for (int i = 1; i <= n; i++) {
		a[i] %= now, b[i] %= now;
		a[i] = (a[i] + now) % now, b[i] = (b[i] + now) % now;
//		cout << a[i] << "  " << b[i] << "\n";
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
	return ;
}
signed main() {
	cin >> T;
	while (T--) solve();
	return 0;
}
/*
6
1
1 1
1
0 2
2
0 3
1 2
2
1 5
2 7
3
-3 5
9 13
7 5
3
-3 11
9 25
7 9
*/