#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,M=5e6+10,INF=1e16;
int n,h,t[M],x[M],y[M],q[M],l=1,r=1,cnt[M],dp[M];
double slope(int i,int j){
	if(x[i]==x[j]&&y[i]>y[j])return -1e18;
	if(x[i]==x[j]&&y[i]<=y[j])return 1e18;
	return (1.0*y[i]-1.0*y[j])/(1.0*x[i]-1.0*x[j]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>h;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		x++;
		m=max(m,x);
		t[x]+=x;
		cnt[x]++;
	}
	for(int i=1;i<=m+h;i++)
		cnt[i]+=cnt[i-1],
		t[i]+=t[i-1];
	r=0;
	for(int i=1;i<=m+h;i++)
	{
		if(i>=h)
		{
			while(l<r&&slope(q[r],i-h)<=slope(q[r-1],q[r]))r--;
			q[++r]=i-h;
		}
		while(l<r&&i*1.0>slope(q[l],q[l+1]))l++;
		int j=q[l];dp[i]=dp[j]+(cnt[i]-cnt[j])*i-(t[i]-t[j]);
		//~ for(int k=l;k<=r;k++)cout<<q[k]<<" ";
		//~ cout<<endl;
		//~ printf("i=%lld,j=%lld,dp[i]=%lld,dp[j]=%lld\n",i,j,dp[i],dp[j]);
		x[i]=cnt[i],y[i]=dp[i]+t[i];
	}
	int ans=INF;
	for(int i=m;i<=m+h;i++)ans=min(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
