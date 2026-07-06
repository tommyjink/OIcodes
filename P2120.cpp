
// dp[i] = min{dp[j] + cal(j, i) + c[i]}
// cal(x, y) = b[y] - b[x] - sum[x] * (dis[y] - dis[x])
// b[x]: [1, x] 移动到 x 的费用
// dp[i] = min{dp[j] + c[i] + b[i] - b[j] - sum[j] * (dis[i] - dis[j])}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
const int N = 1e6 + 10;
int n;
ll x[N], p[N], c[N];
ll s[N], S[N], q[N], f[N];
typedef double db;

db getk(int i, int j) {
	db dy = f[i] + S[i] - f[j] - S[j];
	db dx = s[i] - s[j];
	if (!dx) {
		if (!dy) return 0;
		if (dy > 0) return 1e18;
		if (dy < 0) return -1e18;
	}
	return 1.0 * dy / dx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> x[i] >> p[i] >> c[i];
		s[i] = s[i - 1] + p[i];
		S[i] = S[i - 1] + p[i] * x[i];
	}
	int l = 1, r = 0;
	f[0] = 0; q[++r] = 0;
	rep(i, 1, n) {
		while (l < r && getk(q[l], q[l + 1]) <= x[i]) ++l;
		f[i] = f[q[l]] + c[i] + x[i] * (s[i] - s[q[l]]) - (S[i] - S[q[l]]);
		if (!p[i]) f[i] = min(f[i], f[i - 1]);
		while (l < r && getk(q[r - 1], q[r]) >= getk(q[r - 1], i)) --r;
		q[++r] = i;
	}
	int tot = n;
	ll ans = f[n];
	while (tot && s[tot] == s[tot - 1]) {
		--tot;
		ans = min(ans, f[tot]);
	}
	cout << ans << '\n';
	return 0;
}

