#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,m,a[N][N];
int dpup[N][N],dpdown[N][N];
signed main()
{
	cin>>n>>m;
	memset(dpdown,128,sizeof(dpdown));
	memset(dpup,128,sizeof(dpup));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	dpdown[1][1]=a[1][1];
	dpup[1][1]=a[1][1];
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			dpdown[i][j]=max(dpdown[i][j],dpdown[i-1][j]+a[i][j]);
			dpdown[i][j]=max(dpdown[i][j],dpdown[i][j-1]+a[i][j]);
			dpdown[i][j]=max(dpdown[i][j],dpup[i][j-1]+a[i][j]);
		}
		for(int i=n;i>=1;i--)
		{
			dpup[i][j]=max(dpup[i][j],dpup[i+1][j]+a[i][j]);
			dpup[i][j]=max(dpup[i][j],dpup[i][j-1]+a[i][j]);
			dpup[i][j]=max(dpup[i][j],dpdown[i][j-1]+a[i][j]);
		}
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=m;j++)
		// {
			// printf("%lld ",dpdown[i][j]);
		// }
		// cout<<endl;
	// }
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=m;j++)
		// {
			// printf("%lld ",dpup[i][j]);
		// }
		// cout<<endl;
	// }
	cout<<max(dpup[n][m],dpdown[n][m]);
	return 0;
}