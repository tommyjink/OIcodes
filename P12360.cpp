#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=5e4+10;
set<int> s1,s2;
int n,x;
ll sum;
struct node{
	int p,k;
	bool operator<(const node &o)const{return p>o.p;}
}a[N];
vector<node> q;
vector<int> t;
bool check(int x){
	s2=s1;
	q.clear();t.clear();
	for(int i=1;i<=x;i++)q.push_back(a[i]);
	for(int i=x+1;i<=n;i++){
		q.push_back({a[i].p,-1});
		t.push_back(a[i].k);
	}
	sort(t.begin(),t.end(),greater<int>());
	sort(q.begin(),q.end());
	int st=0;ll res=0;
	for(int i=0;i<n;i++){
		if(q[i].k==-1)q[i].k=t[st++];
		auto it=s2.upper_bound(q[i].k);
		if(it!=s2.end()&&(*it)==q[i].k)it++;
		if(it!=s2.end()){
			s2.erase(it);
			res+=q[i].p;
		}
	}
	return res>sum-res;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i].p=read(),sum+=a[i].p;
	for(int i=1;i<=n;i++)a[i].k=read();
	for(int i=1;i<=n;i++)s1.insert(read());
	int l=0,r=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r<=n?r:-1);
	return 0;
}
