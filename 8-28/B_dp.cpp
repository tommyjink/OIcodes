
#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int f[N][N], n, p;
int main() {
	scanf("%d%d", &n, &p);
	f[n + 1][n + 1] = 1;
	for (int i = n; i >= 1; i--) {
		f[i][i] = (f[i][i] + f[i + 1][i + 1]) % p;
		for (int l = 2 * i; l <= n; l += i) {
			f[i][i] = (f[i][i] + f[l][i + 1]) % p;
			for (int k = i + 1; k <= l - 1; k++) {
				f[k][i] = (f[k][i] + f[l][k + 1]) % p;
			}
		}
		for (int l = 1; l <= n; l++) f[l][i] = (f[l][i] + f[l][i + 1]) % p;
	}
	printf("%d\n", f[1][1]);
	return 0;
}
