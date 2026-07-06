#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int m;
	scanf("%lld",&m);
	while(m--)
	{
		int x;scanf("%lld",&x);
		int p=50,res=5,ans=0;
		while(p-1<=x)
		{
			ans+=res;
			p*=10;
			res+=p/10;
		}
		if(p-res<=x)
			ans+=res-(p-1-x);
		printf("%lld\n",ans);
	}
	return 0;
}