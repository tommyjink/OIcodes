#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n%2==1)
		{
			printf("2\n");
			continue;
		}
		else
		{
			long long a=1,b=0,x=2*n;
			while(x%2==0)
			{
				x/=2;a*=2;
			}
			b=(2*n)/a;
			if(min(a,b)<2)printf("-1\n");
			else if(a<b)printf("%lld\n",a);
			else if(a>b)printf("%lld\n",b);
		}
	}
	return 0;
}
