#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,T,a[N],b[N],t[N],ans[N];
stack<int> stk;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	cin>>T;
	for(int i=1;i<=T;i++)
		cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
			stk.push(a[i]);
		else if(!stk.empty())
		{
			int tp=stk.top();stk.pop();
			int p=(a[i]-tp+1)/2;
			int l=lower_bound(t+1,t+1+T,p)-t;
			ans[l]+=2;
		}
	}
	for(int i=1;i<=T;i++)
		ans[i]+=ans[i-1],
		cout<<n-ans[i]<<endl;
	return 0;
}