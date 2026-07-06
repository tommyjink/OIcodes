#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b)
{
	if(a<b)swap(a,b);
	if(b==0)return a;
	else return gcd(b,a%b);
}
signed main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<gcd(a,gcd(b,c));
	return 0;
}