#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100,M=10000000;
int n,m,a[N],l[M],r[M];
int cntl,cntr,ans=0;
void dfs_l(int ll,int rr,int cnt)
{
	if(cnt>m)return;
	if(ll>rr)
	{
		l[++cntl]=cnt;
		return;
	}
	dfs_l(ll+1,rr,cnt+a[ll]);
	dfs_l(ll+1,rr,cnt);
}
void dfs_r(int ll,int rr,int cnt)
{
	if(cnt>m)return;
	if(ll>rr)
	{
		r[++cntr]=cnt;
		return;
	}
	dfs_r(ll+1,rr,cnt+a[ll]);
	dfs_r(ll+1,rr,cnt);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mid=(1+n)>>1;
	dfs_l(1,mid,0);
	dfs_r(mid+1,n,0);
	sort(l+1,l+1+cntl);
	for(int i=1;i<=cntr;i++)
		ans+=upper_bound(l+1,l+1+cntl,m-r[i])-l-1;
	cout<<ans;
	return 0;
}