#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int n, a[MAXN], p[MAXN], f[20][MAXN]; ll dp[MAXN];

inline 
int ask(int l, int r) {
	int k = __lg(r - l + 1);
	return max(f[k][l], f[k][r - (1 << k) + 1]);
}

inline 
void check(int i, int j) {
	ll w = dp[j] + (ll)ask(j + 1, i) * (n - j);
	if (dp[i] > w) dp[i] = w, p[i] = j;
}

void solve(int l, int r) {
	if (l + 1 == r) return ; int mid = l + r >> 1;
	for (int i = p[l]; i <= p[r]; i++) check(mid, i); solve(l, mid);
	for (int i = l + 1; i <= mid; i++) check(r, i); solve(mid, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), f[0][i] = a[i];
	for (int i = 1; i <= __lg(n); i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
		}
	}
	memset(dp, 0x3f, sizeof dp), *dp = 0;
	check(n, 0), solve(0, n), printf("%lld", dp[n]);
}
