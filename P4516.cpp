
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, MOD = 1e9 + 7;
int n, k;
vector<int> G[N];
int f[2][2][N][105], sz[N], tmp[105][2][2];

void dfs(int u, int fa) {
	sz[u] = 1;
	f[0][0][u][0] = 1;
	f[1][0][u][1] = 1;
	for(auto v : G[u]) {
		if(v == fa) continue;
		dfs(v, u);
		for(int i = 0; i <= min(k, sz[u]); ++i) {
			tmp[i][0][0] = f[0][0][u][i]; f[0][0][u][i] = 0;
			tmp[i][0][1] = f[0][1][u][i]; f[0][1][u][i] = 0;
			tmp[i][1][0] = f[1][0][u][i]; f[1][0][u][i] = 0;
			tmp[i][1][1] = f[1][1][u][i]; f[1][1][u][i] = 0;
		}
		for(int i = 0; i <= k && i <= sz[u]; ++i) {
			for(int j = 0; j + i <= k && j <= sz[v]; ++j) {
				f[0][0][u][i+j] = (1ll * f[0][0][u][i+j] + 1ll * tmp[i][0][0] * f[0][1][v][j]) % MOD;
				f[1][0][u][i+j] = (1ll * f[1][0][u][i+j] + ((1ll * f[0][1][v][j] + f[0][0][v][j]) % MOD * tmp[i][1][0] % MOD)) % MOD;
				f[0][1][u][i+j] = (1ll * f[0][1][u][i+j] + ((1ll * f[1][1][v][j] + f[0][1][v][j]) % MOD * tmp[i][0][1] % MOD) + 1ll * tmp[i][0][0] * f[1][1][v][j] % MOD) % MOD;
				f[1][1][u][i+j] = (1ll * f[1][1][u][i+j] + ((1ll * f[1][1][v][j] + f[0][1][v][j] + f[1][0][v][j] + f[0][0][v][j]) % MOD * tmp[i][1][1] % MOD) + 1ll * tmp[i][1][0] * (f[1][1][v][j] + f[1][0][v][j]) % MOD) % MOD;
			}
		}
		sz[u] += sz[v];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << (1ll * f[1][1][1][k] + f[0][1][1][k]) % MOD << '\n';
	return 0;
}
