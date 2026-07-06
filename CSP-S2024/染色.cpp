#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+5;
int t,n,dp[N][N][N],a[N],ans=0;
int dfs(int k,int x,int y,int val)
{
	if(k>n)
	{
		ans=max(ans,val);
		return val;
	}
	if(dp[k][x][y])
	{
		ans=max(ans,dp[k][x][y]+val);
		return dp[k][x][y]+val;
	}
	dp[k][x][y]=max(dp[k][x][y],dfs(k+1,k,y,val+(a[k]==a[x]?a[k]:0))-val);
	dp[k][x][y]=max(dp[k][x][y],dfs(k+1,x,k,val+(a[k]==a[y]?a[k]:0))-val);
	return dp[k][x][y]+val;
}
signed main()
{
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}