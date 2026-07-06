#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int n,m,f[3001][3001][2],ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	f[1][1][0]=m;
	for(int i=2;i<=n;i++)for(int j=1;j<=i;j++){
		f[i][j+1][0]=(f[i][j+1][0]+f[i-1][j][1]*(m-j))%mod;
		f[i][j][1]=((f[i][j][1]+f[i-1][j][0]+f[i-1][j][1])%mod*j)%mod;
		f[i][j][0]=(f[i][j][0]+f[i-1][j][0]*(m-j))%mod;
	}
	for(int i=1;i<=n;i++)ans=(ans+f[n][i][1])%mod;
	cout<<ans<<endl;
	return 0;
}
