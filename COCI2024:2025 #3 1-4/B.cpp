#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100;
int vis[N],ans=0;
int n,m,x,y,a[N][N];
void dfs(int k,int cnt)
{
	if(k>m)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=1;j<=m;j++)
			{
				if(!vis[j])continue;
				sum+=a[i][j];
			}
			if(sum>=x)res+=sum-x;
		}
		ans=max(ans,res+cnt);
		return;
	}
	vis[k]=false;
	dfs(k+1,cnt);
	vis[k]=true;
	dfs(k+1,cnt-y);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=1;j<=m;j++)
			a[i][j]=s[j-1]-'0';
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}