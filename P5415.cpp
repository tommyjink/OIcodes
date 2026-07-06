
#include <bits/stdc++.h>
using namespace std;
const int N = 155;
const double eps = 1e-12;
int t, n, m, k;
double a[N][N];
int calc(int x, int y) { return (x - 1) * (m + 1) + y; }
void gauss(int n) {
	for (int i = 0; i < n; i++) {
		int id = i;
		for (int j = i + 1; j < n; j++)
			if (fabs(a[j][i]) > fabs(a[id][i])) id = j;
		if (fabs(a[id][i]) < eps) continue;
		swap(a[i], a[id]);
		double div = a[i][i];
		for (int j = 0; j <= n; j++)
			a[i][j] /= div;
		for (int j = i + 1; j < n; j++) {
			double mul = a[j][i];
			for (int k = i; k <= n; k++)
				a[j][k] -= a[i][k] * mul;
		}
	}
	for (int i = n - 1; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			a[j][n] -= a[j][i] * a[i][n], a[j][i] = 0;
}
void solve() {
	memset(a, 0, sizeof(a));
	scanf("%d%d%d", &n, &m, &k);
	int cur = 0, maxp = n * (m + 1);
	a[cur][calc(1, m)] += 1.0, a[cur][maxp] += 1.0;
	cur++;
	for (int i = 2; i <= n; i++) a[cur][calc(i, m)] += 1.0, cur++;
	for (int i = 0; i < m; i++) a[cur][calc(1, i)] += 1.0, a[cur][calc(1, i + 1)] -= 0.25, a[cur][calc(n - 2, 1)] -= 0.75, cur++;
	for (int i = 0; i < m; i++) a[cur][calc(2, i)] += 1.0, a[cur][calc(1, 1)] -= 0.25, a[cur][calc(n - 2, i + 1)] -= 0.25, a[cur][calc(n - 1, 1)] -= 0.5, cur++;
	for (int i = 0; i < m; i++) a[cur][calc(3, i)] += 1.0, a[cur][calc(1, 1)] -= 0.25, a[cur][calc(n - 1, 1)] -= 0.25, a[cur][calc(n - 1, i + 1)] -= 0.25, a[cur][calc(n, 1)] -= 0.25, cur++;
	for (int i = 0; i < m; i++) a[cur][calc(4, i)] += 1.0, a[cur][calc(1, 1)] -= 0.25, a[cur][calc(n, i + 1)] -= 0.25, a[cur][calc(n, 1)] -= 0.5, cur++;
	for (int i = 5; i <= n; i++)
		for (int j = 0; j < m; j++) a[cur][calc(i, j)] += 1.0, a[cur][calc(i - 3, j + 1)] -= 0.25, a[cur][calc(i - 3, 1)] -= 0.75, cur++;
	gauss(maxp);
	double ans = a[calc(k, 0)][maxp];
	printf("%.6lf\n", ans);
}
int main() {
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
