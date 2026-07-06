#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,p,ans=0;
int a[N*2];
int sum[2*N];
int tag[2*N];
signed main()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];	
	}
	for(int i=1;i<=2*n-1;i++)
	{
		sum[i]=(sum[i-1]+a[i])%p;
		if(i>n)tag[sum[i-n]]--;
		ans+=tag[sum[i]];
		if(i<=n)tag[sum[i]]++;
	}
	cout<<ans;
	return 0;
}