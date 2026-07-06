#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int T,n,a[N],sum[N],cnt;
int ans=0;
int cal(int l,int r)
{
	if(l>r)return 0;
	return sum[r]-sum[l-1];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--)
	{
		cin>>n;cnt=(n-1)/2,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=0;i<=cnt;i++)
			ans=max(ans,sum[i]+cal(n-(cnt-i)+1,n));
		cout<<sum[n]-ans<<" "<<ans<<endl;
	}
	return 0;
}