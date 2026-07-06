#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=4e4,K=30,INF=1e16;
int n,k,a[N],f[K][N],t[N],ans;
int l=1,r=0;
void add(int x,int d)
{
	for(int i=x;i<=n;i+=lowbit(i))t[i]+=d;
}
int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))res+=t[i];
	return res;
}
void addL(int i){ans+=query(a[i]);			add(a[i],1);}
void addR(int i){ans+=query(n)-query(a[i]);	add(a[i],1);}
void delL(int i){add(a[i],-1);		ans-=query(a[i]);}
void delR(int i){add(a[i],-1);		ans-=query(n)-query(a[i]);}
int w(int L,int R)
{
	while(l>L)addL(--l);
	while(l<L)delL(l++);
	while(r<R)addR(++r);
	while(r>R)delR(r--);
	//~ cout<<L<<","<<R<<":"<<ans<<endl;
	return ans;
}
void solve(int k,int l,int r,int optl,int optr)
{
	if(l>r)return;
	int mid=(l+r)>>1,p=optl,val=INF;
	for(int i=optl;i<=min(optr,mid-1);i++)
		if(f[k-1][i]+w(i+1,mid)<val)val=f[k-1][i]+ans,p=i;
	f[k][mid]=val;
	solve(k,l,mid-1,optl,p);
	solve(k,mid+1,r,p,optr);
}

signed main()
{
	cin>>n>>k;
	for(int i=n;i>=1;i--)cin>>a[i],f[0][i]=INF;
	for(int i=1;i<=k;i++)solve(i,1,n,0,n);
	//~ for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//~ cout<<endl;
	//~ for(int i=0;i<=k;i++)
		//~ for(int j=0;j<=n;j++)
			//~ printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
	cout<<f[k][n]<<endl;
	return 0;
}
