#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int X=2005;
int n,m,dA,dB;
char g[X][X],ans[X][X];
int deg[X][X];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>dA>>dB;
	for(int i=0;i<n;i++)cin>>g[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(g[i][j]=='#')continue;
		for(int k=0;k<4;k++){
			int ni=i+dx[k],nj=j+dy[k];
			if(0<=ni&&ni<n&&0<=nj&&nj<m&&g[ni][nj]=='.')deg[i][j]++;
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(g[i][j]=='#'){ans[i][j]='#';continue;}
		bool putB=false;
		if(dB>=4){
			if(dB-dA-2*deg[i][j]>0)putB=true;
		}else{
			if(deg[i][j]==0&&dB>dA)putB=true;
		}
		ans[i][j]=putB?'B':'A';
	}
	int best=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(ans[i][j]=='A'){
			int same=0;
			for(int k=0;k<4;k++){
				int ni=i+dx[k],nj=j+dy[k];
				if(0<=ni&&ni<n&&0<=nj&&nj<m&&ans[ni][nj]=='A')same++;
			}
			best+=dA+same;
		}else if(ans[i][j]=='B'){
			int same=0;
			for(int k=0;k<4;k++){
				int ni=i+dx[k],nj=j+dy[k];
				if(0<=ni&&ni<n&&0<=nj&&nj<m&&ans[ni][nj]=='B')same++;
			}
			best+=max(0LL,dB-same);
		}
	}
	cout<<best<<endl;
	for(int i=0;i<n;i++)cout<<ans[i]<<endl;
	return 0;
}
