#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int n,m,tot=0;
int w[N],v[N],dp[N];
signed main()
{
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int vv,ww,kk;
		scanf("%lld%lld%lld",&vv,&ww,&kk);
		for(int j=1;j<=kk;j<<=1)
		{
			w[++tot]=j*ww;
			v[tot]=vv*j;
			kk-=j;
		}
		if(kk)
		{
			w[++tot]=kk*ww;
			v[tot]=vv*kk;
		}
	}
	// for(int i=1;i<=tot;i++)
	// {
		// printf("v%lld w%lld\n",v[i],w[i]);
	// }
	for(int i=1;i<=tot;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	printf("%lld",dp[m]);
	return 0;
}