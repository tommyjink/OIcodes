#include<bits/stdc++.h>
#define int long long
using namespace std;
int tag[10000000]={0,1};
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res*=x;
		y>>=1;
		x*=x;
	}
	return res;
}
signed main()
{
	freopen("test.txt","r",stdin);
	freopen("b.txt","w",stdout);
	int n=0,k=0,ans=0;
	cin>>n>>k;
	// cout<<qpow(3,3);
	for(int i=2;i<=n;i++)
	{
		for(int j=k;qpow(i,j)<=n;j++)
		{
			tag[qpow(i,j)]=true;
		}
	}
	for(int i=1;i<=n;i++)
		if(tag[i])ans++;
	cout<<ans;
	return 0;
}
