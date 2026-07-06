#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans=0;
vector<int> num;
bool check(int x,int k,int d)//x^k<>d
{
	int res=1LL;
	for(int i=1;i<=k;i++)
	{//res*x>1e18 => 1e18/res<x
		if(1e18/res+1LL<x)return 1;
		if(res*x>d)return 1;
		res*=x;
	}
	return 0;
}
int sq(int x,int k)//x^(-k)
{//res_max^k=x
	int l=1,r=1e18;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		//mid^k<>x?
		if(check(mid,k,x))
			r=mid-1;
		else
			l=mid;
	}
	return l;
}
bool check2(int x)
{
	for(int i=0;i<num.size();i++)
		if(x%num[i]==0)return false;
	return true;
}
signed main()
{
	freopen("test.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>n>>k;
	for(int i=k;sq(n,i)>1LL;i++)
	{
		int t=sq(n,i);
		if(i==k||check2(i))
		{
			ans+=t-1;
			num.push_back(i);
			for(int j=k;j<=i-1;j++)
				ans-=sq(t,j)-1;
		}
		// cout<<i<<" "<<ans<<" "<<t<<endl;
	}
	cout<<ans+1<<endl;
	return 0;
}
