#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,INF=1e9;
int n,a[N];
struct node
{
	int l,r,val;
}t[N*4];
void push_up(int k)
{
	t[k].val=max(t[k*2].val,t[k*2+1].val);
}
void build(int k,int l,int r)
{
	t[k].l=l,t[k].r=r;
	if(l==r){return;}
	int mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	push_up(k);
}
void modify(int k,int pos,int d)
{
	if(t[k].r<pos||t[k].l>pos)return;
	if(t[k].l==t[k].r)
	{
		t[k].val=d;
		return;
	}
	modify(k*2,pos,d);
	modify(k*2+1,pos,d);
	push_up(k);
}
int query(int k,int l,int r)
{
	if(t[k].l>r||t[k].r<l)return -INF;
	if(l<=t[k].l&&t[k].r<=r)return t[k].val;
	return max(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);
	modify(1,1,a[1]-n+1);
	for(int i=2;i<=n;i++)
	{
		int l,r;cin>>l>>r;
		int res=query(1,l,r)+n-i;
		res=max(res+a[i],a[i]);
		modify(1,i,res-(n-i));
		
	}
	printf("%lld",query(1,n,n));
	return 0;
}