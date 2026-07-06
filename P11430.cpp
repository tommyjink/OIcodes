#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int n,m,f[N][N],p[N],t[N],o[N];
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		
		scanf("%lld%lld%lld",&p[i],&t[i],&o[i]);
		for(int j=0;j<=m;j++)
			f[i][j]=f[i-1][j];
		for(int j=p[i]+t[i];j<=m;j++)
			f[i][j]=max(f[i][j],f[i-1][j-]);
		printf("%lld%lld:%lld",)
	}
	printf("%lld",f[n][m]);
			
	return 0;
}