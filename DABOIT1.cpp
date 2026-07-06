#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p=998244353,ans=1,res=1;
inline int qpow(int x,int k)
{
	res=1;
	while(k)
	{
		if(k&1)res=res*x%p;
		k>>=1;
		x=x*x%p;
	}
	return res;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		ans=ans*qpow(i,(i*(n*(n-i+1)-(((i+n-2)*(n-i+1))>>1)))%(p-1))%p;
	printf("%lld",ans);
	return 0;
}