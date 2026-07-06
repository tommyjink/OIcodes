#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("b.in","r",stdin);
	// freopen("b.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		int n,m,ans=0,ma=-1;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			printf("n=%lld,i=%lld:\n",n,i);
			int res=0;
			for(int j=1;j<=n;j++)
			{
				int t=(j*i-1)%n+1;
				if(t>j)res+=t,cout<<t<<" ";
				else cout<<"0 ";
			}
			cout<<endl;
			if(res>ma)ma=res,ans=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
8
3 1
5 4
1 1
1000 1
2 2000
1000000000 1145
999999893 2000
1000003 2000


*/