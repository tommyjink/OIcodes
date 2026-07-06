#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a,b,h;
const int mod=1e9+7;
int ans;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
int ny(int x)
{
	return ksm(x,mod-2)%mod;
}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld%lld",&a,&b,&h);
		if(h==0)
		{
			printf("%lld\n",a);
			continue;
		}
		if(a==b)
		{
			printf("%lld\n",ksm(a,h+1));
			continue;
		}
		if(a==1)
		{
			printf("%lld\n",ksm(b,h));
			continue;
		}
		if(b==1)
		{
			ans+=h*(a-1)+a;
			ans%=mod;
			printf("%lld\n",ans);
			continue;
		}
		if(a>b)
		{
			ans%=mod;
			ans+=(ksm(b,h)%mod*a%mod)%mod;
			ans%=mod;
			ans+=((((ksm(b,h)%mod)-1)%mod+mod%mod)%mod)*(ny(b-1)%mod)%mod*(a-b)%mod;
			ans%=mod;
			printf("%lld\n",ans);
		}
		else
		{
			ans+=(ksm(b,h)%mod*a%mod)%mod;
			ans%=mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
