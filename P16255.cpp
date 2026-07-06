#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=80018,P=998244353;
int n,m,k,q,a[N],dp[N],s[N],l[N],r[N];
pii f[N];

void init(){
	dp[0]=1,s[0]=1;
	for(int i=1;i<=n;i++)l[i]=0;
	for(int i=1;i<=k;i++)l[f[i].second]=max(l[f[i].second],f[i].first);
	for(int i=2;i<=n;i++)l[i]=max(l[i],l[i-1]);
	int ip=0;
	for(int i=1,j=0;i<=n;i++){
		ip+=a[i];
		while(ip>=m)j++,ip-=a[j];
		r[i]=j-1;
	}
}

void solve(){
	init();
	for(int i=1;i<=n;i++){
		if(l[i]<=r[i])dp[i]=s[r[i]]-(l[i]==0?0:s[l[i]-1]);
		else dp[i]=0;
		if(dp[i]<0)dp[i]+=P;
		s[i]=s[i-1]+dp[i];
		if(s[i]>=P)s[i]-=P;
	}
	cout<<dp[n]<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++)cin>>f[i].first>>f[i].second;
	solve();
	cin>>q;
	while(q--){
		int c,p;cin>>c>>p;
		if(c==1)cin>>a[p];
		if(c==2)m=p;
		if(c==3)cin>>f[p].first>>f[p].second;
		solve();
	}
	return 0;
}
