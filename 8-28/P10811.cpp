
#include<bits/stdc++.h>
using namespace std;
const int N=2010,M=4000010,st=2000001,inf=0x3f3f3f3f;
int n,a[N+1];
vector<int> v;
bitset<M+1> f;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(a[i])v.push_back(a[i]);
	sort(v.begin(),v.end());
	bool same=1;
	for(int i=1;i<=n;i++)if(a[i]*a[1]<0)same=0;
	if(v.empty())cout<<0;
	else if(same)cout<<v.back();
	else{
		for(int i=0;i+1<v.size();i++){
			if(v[i]>0)f|=f<<v[i];
			else f|=f>>-v[i];
			f[st+v[i]]=1;
		}
		int ans=-inf;
		for(int i=st-2000;i<=st;i++)if(f[i])ans=i;
		cout<<ans-st+v.back();
	}
	return 0;
}
