#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 10, M = 50;
int n, a[N], dp[N][105], ans = 1e9;

int T(int x, int d)
{
	if (d < M)
		return x >> max(0LL, M - d);
	else
		return x << (d - M);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("C/3.in", "r", stdin);
	// freopen("C/3.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 105; j++)
			dp[i][j] = 1e9;

	for (int i = 1; i <= 100; i++)
		dp[1][i] = abs(M-i);

	for (int i = 2; i <= n; i++)
	{
		for (int j = -30; j <= 30; j++)
		{
			int x = T(a[i], M + j), t = M + j;
			for (int k = 20; k < 80; k++)
			{
				if (T(a[i - 1], k) <= x)
				{
					dp[i][t] = min(dp[i][t], dp[i - 1][k] + abs(j));
				}
			}
			printf("dp[%lld][%lld]=%lld,x=%lld\n",i,t,dp[i][t],x);
		}
	}

	for (int i = 1; i <= 100; i++)
		ans = min(ans, dp[n][i]);

	cout << ans << endl;
	return 0;
}
/*

7
9 1 6 3 7 2 8
*/