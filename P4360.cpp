#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,w[N],d[N],c[N],t[N];
int x[N],y[N],dp[N];
int q[N],l=1,r=1;
double slope(int i,int j)
{
	if(x[i]==x[j]&&y[i]>y[j])return -1e18;
	if(x[i]==x[j]&&y[i]<=y[j])return 1e18;
	return (y[i]*1.0-y[j]*1.0)/(x[i]*1.0-x[j]*1.0);
}
signed main()
{
	//~ ios::sync_with_stdio(false);
	//~ cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>d[i];
	for(int i=n;i>=1;i--)d[i]+=d[i+1];
	for(int i=1;i<=n;i++)c[i]=c[i-1]+w[i]*d[i];
	for(int i=1;i<=n;i++)w[i]+=w[i-1];
	for(int i=1;i<=n;i++)t[i]=c[i]-d[i]*w[i];
	//~ for(int i=1;i<=n;i++)
		//~ printf("i=%lld,d=%lld,c=%lld,w=%lld,t=%lld\n",i,d[i],c[i],w[i],t[i]);
	x[1]=w[1],y[1]=t[1];
	q[1]=1;
	for(int i=2;i<=n;i++)
	{
		x[i]=w[i],y[i]=t[i]-c[i];
		int k=-d[i];
		//~ if(l<r)cout<<slope(q[l],q[l+1])<<"???"<<endl;
		while(l<r&&slope(q[l],q[l+1])<k)l++;
		int j=q[l];dp[i]=t[j]+c[i]-c[j]-d[i]*(w[i]-w[j]);
		//~ for(int ii=l;ii<=r;ii++)cout<<x[q[ii]]<<","<<y[q[ii]]<<"|";
		//~ cout<<endl;
		//~ cout<<"^^^^"<<endl;
		//~ printf("!i:%lld,j:%lld,dp[i]:%lld,dp[j]:%lld,k:%lld,x[i]:%lld\n",i,j,dp[i],dp[j],k,x[i]);
		while(l<r&&slope(q[r-1],q[r])>slope(q[r],i))r--;
		q[++r]=i;
	}
	int ans=INF;
	for(int i=2;i<=n;i++)
	{
		ans=min(ans,dp[i]+c[n]-c[i]);
	}
	cout<<ans<<endl;
	return 0;
}
