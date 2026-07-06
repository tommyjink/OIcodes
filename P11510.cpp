#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int ans=1e9+10;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k,x,yy;
	cin>>k>>x>>yy;
	int l=x,p=k-1,y=yy%l;
	int tmp=yy/l;
	if(p*tmp>=y)cout<<yy<<endl;
	else cout<<(tmp+1)*l;
	return 0;
}