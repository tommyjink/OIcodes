#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int mod=19940417,inv2=9970209,inv6=3323403;
int n,m,ans;

int sum1(int x){return x*(x+1)%mod*inv2%mod;}
int sum2(int x){return x*(x+1)%mod*(2*x+1)%mod*inv6%mod;}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(n>m)swap(n,m);
	int tmp1=n*n%mod;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		tmp1=(tmp1-(sum1(r)-sum1(l-1)+mod)%mod*(n/l)%mod+mod)%mod;
	}
	int tmp2=m*m%mod;
	for(int l=1,r;l<=m;l=r+1){
		r=m/(m/l);
		tmp2=(tmp2-(sum1(r)-sum1(l-1)+mod)%mod*(m/l)%mod+mod)%mod;
	}
	int tmp3=0;
	for(int l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		int a=(r-l+1)*n%mod*m%mod;
		int b=(sum1(r)-sum1(l-1)+mod)%mod*((n/l)*m%mod+(m/l)*n%mod)%mod;
		int c=(sum2(r)-sum2(l-1)+mod)%mod*(n/l)%mod*(m/l)%mod;
		tmp3=(tmp3+a-b+c+mod)%mod;
	}
	ans=(tmp1*tmp2%mod-tmp3+mod)%mod;
	cout<<ans<<endl;
	return 0;
}
