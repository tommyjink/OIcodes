#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+10,INF=1e16;
int n,m,a[N],f[N][N],dp[N][N];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
		f[i][0]=max(f[i-1][0],dp[i][0]-a[i]);
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][k]=max(dp[i-1][k],f[i][k-1]+a[i]);
			//~ printf("dp[%lld][%lld]=%lld\n",i,k,dp[i][k]);
		}
		for(int i=1;i<=n;i++)
			f[i][k]=max(f[i-1][k],dp[i][k]-a[i]);
		//~ for(int i=1;i<=n;i++)
			//~ printf("dp[%lld][%lld]=%lld\n",i,k,dp[i][k]);
		//~ for(int i=1;i<=n;i++)
			//~ printf("f[%lld][%lld]=%lld\n",i,k,f[i][k]);
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
