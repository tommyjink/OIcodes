#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000];
int dp[105][1005];//dp[i][j]
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j-a[i]>=0)dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];
			else dp[i][j]=dp[i-1][j];
		}
	}
		
	// for(int i=0;i<=n;i++)
	// {
		// for(int j=0;j<=m;j++)
		// {
			// printf("%lld ",dp[i][j]);
		// }
		// printf("\n");
	// }
		
	cout<<dp[n][m];
	return 0;
}