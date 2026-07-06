#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=300;
int n,m,a[N][N],b[N],c[N];
int cal()
{
	int ans=0;
	c[0]=0;
	for(int i=1;i<=m;i++)
		c[i]=min(c[i-1],b[i]);
	for(int i=1;i<=m;i++)
	{
		int l=0,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(c[mid]<=b[i])r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]+=a[i-1][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]+=a[i][j-1];
	int ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			for(int i=1;i<=m;i++)
				b[i]=a[r][i]-a[l-1][i];
			ans=max(ans,cal()*(r-l+1));
		}
	}
	cout<<ans<<endl;
	return 0;
}