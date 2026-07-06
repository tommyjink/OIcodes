#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e2+10;
int n,mp[N][N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=1;j<=n;j++)
			if(s[j-1]=='.')
				mp[0][j]=i,
				mp[i][0]=j;
	}
	int res1=1,res2=1;
	for(int i=1;i<=n;i++)
	{
		if(!mp[i][0])res1=0;
		if(!mp[0][i])res2=0;
	}
	if(!res1&&!res2)cout<<"-1";
	else if(res1)
		for(int i=1;i<=n;i++)
			cout<<i<<" "<<mp[i][0]<<endl;
	else
		for(int i=1;i<=n;i++)
			cout<<mp[0][i]<<" "<<i<<endl;
	return 0;
}