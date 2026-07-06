#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,typ,a[N],pref[N],p[N],s[N],x[N];
int cur[N],rest[N],ans;
bool inq[N];
int q[N],head,tail;
int seq[N],top;
bool can(int pos){
	if(pos<1||pos>n||rest[pos]==0)return false;
	if(pos==1)return cur[2]>0;
	if(pos==n)return cur[n-1]>0;
	return cur[pos-1]>0&&cur[pos+1]>0;
}
void push(int pos){
	if(1<=pos&&pos<=n&&!inq[pos]){
		inq[pos]=true;
		q[tail++]=pos;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>typ;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		pref[i]=pref[i-1]+a[i]-1;
		p[i]=pref[i];
	}
	int mn=0;
	for(int i=n-1;i>=1;i--){
		s[i]=s[i+1]+p[i];
		mn=min(mn,s[i]);
	}
	ans=0;
	for(int i=1;i<=n;i++){
		x[i]=s[i]-mn;
		ans+=x[i];
	}
    cout<<ans<<endl;
	if(typ==0)return 0;
	for(int i=1;i<=n;i++)cur[i]=1,rest[i]=x[i];
	cur[0]=cur[n+1]=4e18;
	for(int i=1;i<=n;i++)push(i);
	while(head<tail){
		int pos=q[head++];
		inq[pos]=false;
		if(!can(pos))continue;
		rest[pos]--;
		seq[++top]=pos;
		if(pos==1)cur[2]--,cur[1]++;
		else if(pos==n)cur[n-1]--,cur[n]++;
		else cur[pos-1]--,cur[pos+1]--,cur[pos]+=2;
		for(int j=pos-2;j<=pos+2;j++)push(j);
	}
	for(int i=1;i<=top;i++)cout<<seq[i]<<' ';
	cout<<endl;
	return 0;
}
