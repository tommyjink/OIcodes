
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, K = 205;
ll id, Q, n, m, t, p, ans;
ll v[N][2], s[N][2], f[N][K][2];

int main() {
	scanf("%lld%lld", &id, &Q);
	while (Q--) {
		scanf("%lld%lld%lld%lld", &n, &m, &t, &p);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld%lld", &v[i][0], &v[i][1]);
			s[i][0] = s[i - 1][0] + v[i][0];
			s[i][1] = s[i - 1][1] + v[i][1];
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				for (int k = 0; k < 2; ++k)
					f[i][j][k] = -1e18;
		for (int i = 1; i <= n; ++i) {
			f[i][0][0] = s[i][0];
			f[i][0][1] = s[i][1];
		}
		ans = max(s[n][0], s[n][1]);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				for (int k = 0; k < 2; ++k) {
					for (int x = 1; x < i; ++x) {
						ll u = f[x][j - 1][k ^ 1] + s[i - 1][k ^ 1] - s[x][k ^ 1] + v[i][k] + ((i - x <= t && j > 1) ? p : 0);
						f[i][j][k] = max(f[i][j][k], u);
					}
					ans = max(ans, f[i][j][k] + s[n][k] - s[i][k]);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
