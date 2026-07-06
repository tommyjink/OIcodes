#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10;
struct node{int a,b,c,cnt,ans;}b[N],a[N];
int n,m,k,t[N],ans[N];
bool cmpA(node x,node y){return x.a==y.a?(x.b==y.b?x.c<y.c:x.b<y.b):x.a<y.a;}
bool cmpB(node x,node y){return x.b==y.b?x.c<y.c:x.b<y.b;}
bool cmpC(node x,node y){return x.c<y.c;}
void add(int x,int d){for(;x<=k;x+=lowbit(x))t[x]+=d;}
int sum(int x){int res=0;for(;x;x-=lowbit(x))res+=t[x];return res;}
void CDQ(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	CDQ(l,mid);
	CDQ(mid+1,r);
	sort(a+l,a+1+mid,cmpB);
	sort(a+mid+1,a+1+r,cmpB);
	int i=l;
	for(int j=mid+1;j<=r;j++)
	{
		while(i<=mid&&a[i].b<=a[j].b)add(a[i].c,a[i].cnt),i++;
		a[j].ans+=sum(a[j].c);
	}
	for(int j=l;j<i;j++)add(a[j].c,-a[j].cnt);
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>b[i].a>>b[i].b>>b[i].c,b[i].cnt=1;
	sort(b+1,b+1+n,cmpA);
	for(int i=1;i<=n;i++)
	{
		if(i>1&&b[i].a==b[i-1].a&&b[i].b==b[i-1].b&&b[i].c==b[i-1].c)
			a[m].cnt++;
		else a[++m]=b[i];
	}
	CDQ(1,m);
	for(int i=1;i<=m;i++)
		ans[a[i].ans+a[i].cnt-1]+=a[i].cnt;
	for(int i=0;i<n;i++)cout<<ans[i]<<endl;
	return 0;
}
