#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200,M=1e6+10;
int n,a[N],l[M],r[M],cntl,cntr,ans=0;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				l[++cntl]=a[i]*a[j]+a[k];
				if(a[k])r[++cntr]=(a[i]+a[j])*a[k];
			}
				
	// for(int i=1;i<=cntl;i++)
	// {
		// cout<<l[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=1;i<=cntr;i++)
	// {
		// cout<<r[i]<<" ";
	// }
	// cout<<endl;
	sort(l+1,l+1+cntl);
	for(int i=1;i<=cntr;i++)
	{
		ans+=upper_bound(l+1,l+1+cntl,r[i])-l;
		ans-=lower_bound(l+1,l+1+cntl,r[i])-l;
	}
	cout<<ans;
	return 0;
}