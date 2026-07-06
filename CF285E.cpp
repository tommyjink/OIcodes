
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005, mod = 1e9 + 7;

int n, k;
int dp[N][N][2][2];
int fac[N], inv[N];

int qread() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while ('0' <= c && c <= '9') { x = x * 10 + (c ^ 48); c = getchar(); }
	return x * f;
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
	if (n < m || m < 0) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int F(int x) {
	return (dp[n][x][0][0] + dp[n][x][1][0]) % mod * fac[n - x] % mod;
}

int G(int x) {
	int res = 0;
	for (int i = x; i <= n; i++) {
		int now = C(i, x) * F(i) % mod;
		if ((i - x) & 1) res = (res - now + mod) % mod;
		else res = (res + now) % mod;
	}
	return res;
}

signed main() {
	n = qread(), k = qread();
	init(n);
	dp[1][0][0][0] = dp[1][1][0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j) {
				dp[i][j][0][0] = (dp[i][j][0][0] + dp[i - 1][j - 1][0][0]) % mod;
				dp[i][j][1][0] = (dp[i][j][1][0] + dp[i - 1][j - 1][0][1]) % mod;
				dp[i][j][0][1] = (dp[i][j][0][1] + dp[i - 1][j - 1][0][0] + dp[i - 1][j - 1][1][0]) % mod;
				dp[i][j][1][1] = (dp[i][j][1][1] + dp[i - 1][j - 1][0][1] + dp[i - 1][j - 1][1][1]) % mod;
			}
			dp[i][j][0][0] = (dp[i][j][0][0] + dp[i - 1][j][0][0] + dp[i - 1][j][1][0]) % mod;
			dp[i][j][1][0] = (dp[i][j][1][0] + dp[i - 1][j][0][1] + dp[i - 1][j][1][1]) % mod;
		}
	}
	printf("%lld\n", G(k));
	return 0;
}

