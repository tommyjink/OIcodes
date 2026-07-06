#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,s,t[N],c[N],q[N],top=1;
int x[N],y[N],dp[N];
double slope(int i,int j)
{
	if(x[i]==x[j]&&y[i]>y[j])return -1e18;
	if(x[i]==x[j]&&y[i]<=y[j])return 1e18;
	return (y[i]*1.0-y[j]*1.0)/(x[i]*1.0-x[j]*1.0);
}
int find(int k)
{
	int l=1,r=top;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(slope(q[mid],q[mid+1])<=1.0*k)l=mid+1;
		else r=mid;
	}
	return q[l];
}
signed main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>c[i];
		t[i]+=t[i-1];
		c[i]+=c[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int j=find(s+t[i]);
		dp[i]=dp[j]+s*(c[n]-c[j])+(c[i]-c[j])*t[i];
		x[i]=c[i],y[i]=dp[i];
		//~ printf("i=%lld,j=%lld,dp[i]=%lld,dp[j]=%lld\n",i,j,dp[i],dp[j]);
		while(top>1&&slope(q[top-1],q[top])>slope(q[top],i))top--;
		q[++top]=i;
	}
	cout<<dp[n]<<endl;
	return 0;
}
