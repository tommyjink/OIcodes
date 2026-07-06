#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e3+100;
int n,mp[N][N];
int col[N][N][3];
int vis[N][N],cnt=0;
struct node
{
	int x,y,c;
};
queue<node> q;
stack<node> ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
			if(++col[i][0][mp[i][j]]==n)
				q.push((node){i,0,mp[i][j]});
			if(++col[0][j][mp[i][j]]==n)
				q.push((node){0,j,mp[i][j]});
			if(mp[i][j]==0)vis[i][j]=true;
		}
	}
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if(mp[t.x][t.y])continue;
		else mp[t.x][t.y]=true;
		// cout<<t.x<<" "<<t.y<<" "<<t.c<<endl;
		ans.push((node){(t.x==0)+1,t.x+t.y,t.c});
		if(t.x)
		{
			for(int i=1;i<=n;i++)
			{
				mp[t.x][i]=3;
				if(!vis[t.x][i])cnt++;
				vis[t.x][i]=true;
				col[0][i][t.c]--;
				if(++col[0][i][1]==n)
					q.push((node){0,i,1});
				if(++col[0][i][2]==n)
					q.push((node){0,i,2});
			}
		}
		else if(t.y)
		{
			for(int i=1;i<=n;i++)
			{
				mp[i][t.y]=3;
				if(!vis[i][t.y])cnt++;
				vis[i][t.y]=true;
				col[i][0][t.c]--;
				if(++col[i][0][1]==n)
					q.push((node){i,0,1});
				if(++col[i][0][2]==n)
					q.push((node){i,0,2});
			}
		}
		if(cnt==n*n)break;
	}
	bool done=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j]!=0&&mp[i][j]!=3)
				done=false;
	if(done)
	{
		cout<<ans.size()<<endl;
		while(!ans.empty())
		{
			node t=ans.top();
			cout<<t.x<<" "<<t.y<<" "<<t.c<<endl;
			ans.pop();			
		}
	}
	else cout<<"-1";
	return 0;
}