#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
int T,k,m,n;
vector<int> a;
vector<vector<int> > f;
void build(int u,int l,int r)
{
	int len=r-l;
	f[u].assign(len,0);
	if(len==1)return;
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid,r);
	int half=len>>1;
	for(int x=0;x<len;x++)
	{
		int low=x&(half-1);
		f[u][x]=f[u<<1][low]+f[u<<1|1][low]+(a[(mid-1)^x]==a[mid^x]);
	}
}
int id(int l,int len)
{
	int t=__builtin_ctz(len),d=k-t;
	return(1<<d)+(l>>t);
}
int ask(int u,int l,int r,int ql,int qr,int y)
{
	if(ql<=l&&r-1<=qr)
	{
		int len=r-l,low=y&(len-1);
		int high=y^low,realL=l^high;
		return f[id(realL,len)][low];
	}
	int mid=(l+r)>>1,ans=0;
	bool hl=0,hr=0;
	if(ql<mid)ans+=ask(u<<1,l,mid,ql,qr,y),hl=1;
	if(qr>=mid)ans+=ask(u<<1|1,mid,r,ql,qr,y),hr=1;
	if(hl&&hr)ans+=(a[(mid-1)^y]==a[mid^y]);
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T>>k>>m;
	n=1<<k;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	f.resize(max(2LL,2*n));
	build(1,0,n);
	int ls=0,y=0;
	while(m--)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x;cin>>x;
			x^=T*ls;
			y^=x;
		}
		else
		{
			int l,r;cin>>l>>r;
			l^=T*ls,r^=T*ls;
			if(l>r)swap(l,r);
			int s=ask(1,0,n,l,r,y);
			ls=r-l+1-s;
			cout<<ls<<endl;
		}
	}
	return 0;
}
