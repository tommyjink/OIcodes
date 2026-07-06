#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,x,y,q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k>>x>>y>>q;
	int p=x+y*(k-1);
	int r=(n/k)*p+(n%k)*y;
	// cout<<p<<" "<<r<<endl;
	while(q--)
	{
		int a,ans=0;
		cin>>a;
		a%=r;
		if(a==0)
		{
			cout<<n<<endl;
			continue;
		}
		ans+=(a/p)*k;
		a%=p;
		if(a==0)
		{
			cout<<ans<<endl;
			continue;
		}
		if(a<=p-x)
			ans+=(a+(y-1))/y;
		else ans+=k;
		cout<<ans<<endl;
	}
	
	
	return 0;
}