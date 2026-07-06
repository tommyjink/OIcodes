#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,f[N][35],cnt[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		int res=0,tmp=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			f[i][0]=x;
		}
		for(int i=1;i<=30;i++)
			for(int j=1;j<=n;j++)
				f[j][i]=f[f[j][i-1]][i-1];
		for(int i=1;i<=n;i++)
			cnt[f[i][30]]++;
		for(int i=1;i<=n;i++)
			res+=cnt[i]*(n-cnt[i]-tmp),
			tmp+=cnt[i];
		cout<<res<<endl;
	}
	return 0;
}