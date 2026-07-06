#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int a,b;
	cin>>a>>b;
	if(a==1||b==1)
		cout<<2*(a*b-1)<<".00";
	else if(a%2&&b%2)
		printf("%.2lf",a*b-1+sqrt(2));
	else cout<<a*b<<".00";
	return 0;
}