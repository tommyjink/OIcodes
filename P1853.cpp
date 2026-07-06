#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5,M=1e5+5,K=1e5;
int aa[N],bb[N],s,n,dd,d=0;
int dp[M],a[K],b[K];
signed main()
{
	cin>>s>>n>>dd;
	for(int i=1;i<=dd;i++)
		cin>>aa[i]>>bb[i];
	for(int i=1;i<=dd;i++)
	{
		int tot=0;
		for(int j=1;tot<=s*100;j<<=1)
		{
			a[++d]=j*aa[i];
			b[d]=j*bb[i];
			tot+=a[d];
		}
	}
	for(int i=1;i<=d;i++)
	{
		for(int j=s/10;j>=1;j--)
		{
			if(j>=a[i]/1000)
				dp[j]=max(dp[j],dp[j-a[i]/1000]+b[i]);
		}
	}
	while(n--)
	{
		s+=dp[s/1000];
	}
	cout<<s;
	return 0;
}