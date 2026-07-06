#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e3+10,K=15+10,mod=1e9+7;
int n,m,t[K];
char ts[K];
int f[2][3][1<<15];
int s[K],ans[K];

int trans(int k,int ch){
	for(int i=0;i<m;i++)s[i]=(k>>i&1)+(i==0?0:s[i-1]);
	int sf=0,ret=0;
	for(int i=0;i<m;i++){
		int cur=max(s[i],sf);
		if(t[i]==ch)cur=max(cur,(i==0?0:s[i-1])+1);
		ret|=(cur-sf)<<i;
		sf=cur;
	}
	return ret;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>ts;
	for(int i=0;i<m;i++)t[i]=(ts[i]=='N'?0:(ts[i]=='O'?1:2));
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++)for(int k=0;k<(1<<m);k++)f[i&1^1][j][k]=0;
		for(int j=0;j<3;j++)for(int k=0;k<(1<<m);k++){
			if(!f[i&1][j][k])continue;
			for(int c=0;c<(j==2?2:3);c++)
				(f[i&1^1][(j==c?j+1:(c==0?1:0))][trans(k,c)]+=f[i&1][j][k])%=mod;
		}
	}
	for(int i=0;i<(1<<m);i++){
		int pc=__builtin_popcountll(i);
		(ans[pc]+=(f[n&1][0][i]+f[n&1][1][i]+f[n&1][2][i])%mod)%=mod;
	}
	for(int i=0;i<=m;i++)cout<<ans[i]<<endl;
	return 0;
}
