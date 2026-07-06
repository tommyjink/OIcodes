#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,tot[2]={0},head[2][N];
int siz[2][N],vis[2][N],ans=0;
struct node
{
	int to,next;
}e[2][N*2];
void add(int x,int y,int num)
{
	e[num][++tot[num]]=(node){y,head[num][x]};
	head[num][x]=tot[num];
}
void bfs(int s,int num,int k)
{
	queue<int> q;q.push(s);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		if(vis[num][t]==k)continue;
		siz[num][s]++,vis[num][t]=k;
		for(int i=head[num][t];i;i=e[num][i].next)
		{
			int v=e[num][i].to;
			if(vis[num][v]==k)continue;
			q.push(v);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y,0);
		add(y,x,1);
	}
	for(int i=1;i<=n;i++)
		bfs(i,0,i),bfs(i,1,i);
	// for(int i=1;i<=n;i++)
		// cout<<siz[0][i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++)
		// cout<<siz[1][i]<<" ";
	for(int i=1;i<=n;i++)
		if(siz[0][i]+siz[1][i]-1==n)
			ans++;
	cout<<ans<<endl;
	return 0;
}