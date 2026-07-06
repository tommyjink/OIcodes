#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e16;
int n,k,a[N],l=1,r=0;
int cnt[N],ans=0,f[25][N];
void add(int i)
{
	ans+=cnt[a[i]];
	cnt[a[i]]++;
}
void del(int i)
{
	cnt[a[i]]--;
	ans-=cnt[a[i]];
}
int w(int L,int R)
{
	while(l>L)add(--l);
	while(l<L)del(l++);
	while(r>R)del(r--);
	while(r<R)add(++r);
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
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)f[0][i]=INF;
	f[0][0]=0;
	for(int i=1;i<=k;i++)solve(i,1,n,0,n);
	//~ for(int i=0;i<=k;i++)
		//~ for(int j=0;j<=n;j++)
			//~ printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
	cout<<f[k][n]<<endl;
	return 0;
}
