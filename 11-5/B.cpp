#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int T,n,id,p[N],siz[N];
long long ans[N];
long long get(int x,int n){
	if(x==1)return 1;
	return get(p[x],n)+n/p[x]-x/p[x]+1;
}
void init(int n){
	p[1]=0;
	for(int i=2;i<=n;i++){
		if(!p[i]){
			p[i]=i;
			for(int j=(i<<1);j<=n;j+=i)p[j]=max(p[j],i);
		}
	}
	for(int i=2;i<=n;i++)p[i]=i/p[i];
	for(int i=1;i<=n;i++){
		int sum=1;
		for(int j=(i<<1);j<=n;j+=i){
			if(sum>1)ans[j]+=sum-1;
			for(int k=j;k;k=p[k]){
				if(k==i)sum++;
			}
		}
	}
	siz[1]=1;
	for(int i=2;i<=n;i++){
		ans[i]+=ans[i-1];
		ans[i]+=get(i,i);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	init(N-5);
	cin>>T;
	while(T--){
		cin>>n;
		cout<<ans[n]+1<<'\n';
	}
	return 0;
}

