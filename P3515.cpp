#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,h[N],f[N];
double w(int i,int j){return 1.0*h[i]+sqrt(1.0*(abs(i-j)));}
void solve(int l,int r,int optl,int optr)
{
	if(l>r)return;
	int mid=(l+r)>>1,p=optl;
	for(int i=optl;i<=min(optr,mid);i++)
		if(w(i,mid)>w(p,mid))p=i;
	f[mid]=max(f[mid],(int)ceil(w(p,mid)));
	solve(l,mid-1,optl,p);
	solve(mid+1,r,p,optr);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	solve(1,n,1,n);
	reverse(h+1,h+1+n);
	reverse(f+1,f+1+n);
	solve(1,n,1,n);
	reverse(h+1,h+1+n);
	reverse(f+1,f+1+n);
	for(int i=1;i<=n;i++)
		cout<<f[i]-h[i]<<endl;
	return 0;
}
