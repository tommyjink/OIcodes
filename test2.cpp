#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3;
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
int n,m,mp[N][N],vis[N][N];
int ans=1e9;
void dfs(int x,int y,int dep)
{
	if(x==n&&y==m)
	{
		ans=min(ans,dep);
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(vis[xx][yy])continue;
		if(mp[xx][yy])continue;
		vis[xx][yy]=true;
		dfs(xx,yy,dep+1);
		vis[xx][yy]=false;
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	dfs(1,1,0);
	if(ans==1e9)cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}