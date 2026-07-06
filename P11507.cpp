#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a,b,c;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>a>>b>>c;
	while(a||b||c)
	{
		if(b) b--,n=(n+1)/2;
		else if(a) a--,n/=2;
		else c--,n=max((n-1)/2,0LL);
	}
	cout<<n<<endl;
	return 0;
}