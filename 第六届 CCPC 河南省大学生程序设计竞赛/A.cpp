#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,d;
	cin>>n>>d;
	long long l=to_string(n).size();
	long long ans=(1234567890*1ll+d);
	ans=ans*pow(10,l);
	ans=(ans+n)/n;
	cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long t;
	cin>>t;
	while(t--)
		solve();
	return 0; 
}
