#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,typ,a[N],d[N],y[N],x[N],r[N],ans;
bool inq[N];
int q[N],head,tail;
int seq[N],top;

bool legal(int i){
	if(i<1||i>n||r[i]==0)return false;
	if(i==1)return r[1]>=r[2];
	if(i==n)return r[n]>=r[n-1];
	return 2*r[i]-r[i-1]-r[i+1]>=1;
}

void push(int i){
	if(i<1||i>n)return;
	if(!inq[i]&&legal(i))inq[i]=1,q[tail++]=i;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>typ;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)d[i]=d[i-1]+a[i]-1;
	y[1]=0;int mn=y[1];
	for(int i=1;i<n;i++){
		y[i+1]=y[i]-d[i];
		mn=min(mn,y[i+1]);
	}
	for(int i=1;i<=n;i++){
		x[i]=y[i]-mn;
		ans+=x[i];
	}
	cout<<ans<<endl;
	if(typ==0)return 0;
	for(int i=1;i<=n;i++)r[i]=x[i];
	for(int i=1;i<=n;i++)push(i);
	while(top<ans){
		int p=q[head++];inq[p]=false;
		if(!legal(p))continue;
		r[p]--,seq[++top]=p;
		push(p-1),push(p),push(p+1);
	}
	for(int i=top;i>=1;i--)cout<<seq[i]<<' ';
	cout<<endl;
	return 0;
}
