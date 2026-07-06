#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int X=2005;
int n,m,dA,dB;
char g[X][X],ans[X][X];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>dA>>dB;
	for(int i=0;i<n;i++)cin>>g[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans[i][j]=g[i][j];
	if(dB>=4){
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			if(g[i][j]=='#')continue;
			int deg=0;
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(0<=x&&x<n&&0<=y&&y<m&&g[x][y]=='.')deg++;
			}
			if(dA+2*deg>dB)ans[i][j]='A';
			else ans[i][j]='B';
		}
	}else{
		bool vis[X][X]={};
		for(int si=0;si<n;si++)for(int sj=0;sj<m;sj++){
			if(g[si][sj]=='#'||vis[si][sj])continue;
			pii comp[X*X];
			queue<pii> q;
			int top=0;
			q.push({si,sj}),vis[si][sj]=1;
			int cnt=0,sumDeg=0,scoreB=0;
			while(!q.empty()){
				pii p=q.front();q.pop();
				int x=p.first,y=p.second;
				comp[++top]={x,y},cnt++;
				int deg=0;
				for(int k=0;k<4;k++){
					int nx=x+dx[k],ny=y+dy[k];
					if(0<=nx&&nx<n&&0<=ny&&ny<m&&g[nx][ny]=='.'){
						deg++;
						if(!vis[nx][ny])vis[nx][ny]=1,q.push({nx,ny});
					}
				}
				sumDeg+=deg,scoreB+=max(0LL,dB-deg);
			}
			int edges=sumDeg/2,scoreA=cnt*dA+2*edges;
			char put=scoreA>=scoreB?'A':'B';
			for(int i=1;i<=top;i++)ans[comp[i].first][comp[i].second]=put;
		}
	}
	int total=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(ans[i][j]=='A'){
			int cur=dA;
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(0<=x&&x<n&&0<=y&&y<m&&ans[x][y]=='A')cur++;
			}
			total+=cur;
		}else if(ans[i][j]=='B'){
			int cur=dB;
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(0<=x&&x<n&&0<=y&&y<m&&ans[x][y]=='B')cur--;
			}
			total+=max(0LL,cur);
		}
	}
	cout<<total<<endl;
	for(int i=0;i<n;i++)cout<<ans[i]<<endl;
	return 0;
}
