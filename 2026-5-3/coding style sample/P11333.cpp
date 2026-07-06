#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],q[N],l=1,r=1;
int x[N],y[N],dp[N];
double slope(int i,int j)
{
	if(x[i]==x[j]&&y[i]>y[j])return -1e18;
	if(x[i]==x[j]&&y[i]<=y[j])return 1e18;
	return (y[i]*1.0-y[j]*1.0)/(x[i]*1.0-x[j]*1.0);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]=max(a[i],a[i-1]);
	for(int i=1;i<=n;i++)
	{
		while(l<r&&slope(q[l],q[l+1])<a[i])l++;
		int j=q[l];dp[i]=dp[j]+a[i]*(n-j);
		x[i]=i,y[i]=dp[i];
		while(l<r&&slope(q[r-1],q[r])>slope(q[r],i))r--;
		q[++r]=i;
	}
	cout<<dp[n]<<endl;
	return 0;
}
