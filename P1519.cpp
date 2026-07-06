#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000;
int n,m,ox[5],oy[5],tot=0;
int dx[]={0,0,-2,2};
int dy[]={2,-2,0,0};
int mp[N][N],mem[N][N],ans=-1,vis[N][N];
struct node{int x,y;};
void bfs(int x,int y)
{
	// cout<<x<<" "<<y<<endl;
	queue<node> q;
	q.push((node){x,y});
	mem[x][y]=1;
	while(!q.empty())
	{
		node t=q.front();q.pop();
		// cout<<t.x<<" "<<t.y<<endl;
		for(int i=0;i<4;i++)
		{
			int xx=t.x+dx[i];
			int yy=t.y+dy[i];
			if(xx<1||yy<1||xx>2*n+1||yy>2*m+1)continue;
			if(mp[t.x+dx[i]/2][t.y+dy[i]/2])continue;
			if(mp[xx][yy])continue;
			if(vis[xx][yy])continue;
			if(!mem[xx][yy])mem[xx][yy]=mem[t.x][t.y]+1;
			else mem[xx][yy]=min(mem[xx][yy],mem[t.x][t.y]+1);
			vis[xx][yy]=1;
			q.push((node){xx,yy});
		}
	}
}
signed main()
{
	cin>>m>>n;
	for(int i=1;i<=2*n+1;i++)
	{
		for(int j=1;j<=2*m+1;j++)
		{
			char c;c=getchar();
			while(c!='+'&&c!='-'&&c!=' '&&c!='|')c=getchar();
			if(c==' ')mp[i][j]=0;
			else mp[i][j]=1;
			if(c==' '&&(i==1||j==1||i==2*n+1||j==2*m+1))
				ox[++tot]=i,oy[tot]=j;
		}
	}
	mp[ox[1]][oy[1]]=1;
	mp[ox[2]][oy[2]]=1;
	for(int i=0;i<4;i++)
	{
		int xx=ox[2]+dx[i]/2;
		int yy=oy[2]+dy[i]/2;
		if(xx<=2*n+1&&yy<=2*m+1
		&&xx>=1&&yy>=1&&!mp[xx][yy])bfs(xx,yy);
	}
	// for(int i=1;i<=2*n+1;i++)
	// {
		// for(int j=1;j<=2*m+1;j++)
		// {
			// if(mem[i][j])
			// cout<<mem[i][j]<<" ";
			// else cout<<"|";
		// }
		// cout<<endl;
	// }
	memset(vis,0,sizeof(vis));
	for(int i=0;i<4;i++)
	{
		int xx=ox[1]+dx[i]/2;
		int yy=oy[1]+dy[i]/2;
		if(xx<=2*n+1&&yy<=2*m+1
		&&xx>=1&&yy>=1&&!mp[xx][yy])bfs(xx,yy);
	}
	// for(int i=1;i<=2*n+1;i++)
	// {
		// for(int j=1;j<=2*m+1;j++)
		// {
			// if(mem[i][j])
			// cout<<mem[i][j]<<" ";
			// else cout<<"|";
		// }
		// cout<<endl;
	// }
	for(int i=1;i<=2*n+1;i++)
	{
		for(int j=1;j<=2*m+1;j++)
		{
			ans=max(ans,mem[i][j]);
		}
	}
	cout<<ans;
	return 0;
}