#include <bits/stdc++.h>
using namespace std;
const int N = 31;
int t, n, a[N][2];
long long f[N + 1][2];
char op[N][2];
int main()
{
	cin >> t;
	while (t--)
	{
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> op[i][0] >> a[i][0] >> op[i][1] >> a[i][1];
		f[n + 1][0] = f[n + 1][1] = 1;
		for (int i = n; i >= 1; i--)
		{
			for (int j = 0; j <= 1; j++)
				if (op[i][j] == '+')
				{
					f[i][j] = f[i + 1][j];
					ans += a[i][j] * max(f[i + 1][0], f[i + 1][1]);
				}
				else f[i][j] = f[i + 1][j] + (a[i][j] - 1) * max(f[i + 1][0], f[i + 1][1]);
		}
		cout << ans + f[1][0] + f[1][1] << endl;
	}
	return 0;
}
