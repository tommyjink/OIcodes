#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int a[3][N][N],n,q,ans=0;
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);	
	cin>>n>>q;
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		x++,y++,z++;
		if((++a[0][x][y])==n)ans++;
		if((++a[1][x][z])==n)ans++;
		if((++a[2][y][z])==n)ans++;
		cout<<ans<<endl;
	}
	return 0;
}