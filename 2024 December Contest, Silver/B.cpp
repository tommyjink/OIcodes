#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int T,n,k,x[N],l[N],r[N],tt[N];
int lazy[N*8];
struct node
{
	int l,r,val;
}t[N*8];
struct Node
{
	int l,r;
}q[N];
bool cmp(Node x,Node y)
{
	if(x.l==y.l)return x.r<y.r;
	else return x.l<y.l;
}
void push_up(int k)
{
	t[k].val=t[k*2].val+t[k*2+1].val;
}
void push_down(int k)
{
	t[k*2].val+=lazy[k];
	t[k*2+1].val+=lazy[k];
	lazy[k*2]+=lazy[k];
	lazy[k*2+1]+=lazy[k];
	lazy[k]=0;
}
void build(int k,int l,int r)
{
	t[k].l=l,t[k].r=r;
	if(l==r)
	{
		t[k].val=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	push_up(k);
}
void add(int k,int l,int r,int d)
{
	if(t[k].l>r||t[k].r<l)return;
	if(l<=t[k].l&&t[k].r<=r)
	{
		lazy[k]+=d;
		t[k].val+=d;
		return;
	}
	push_down(k);
	add(k*2,l,r,d);
	add(k*2+1,l,r,d);
	push_up(k);
}
int query(int k,int l,int r)
{
	if(t[k].l>r||t[k].r<l)return 0;
	if(l<=t[k].l&&t[k].r<=r)return t[k].val;
	push_down(k);
	int res=0;
	res+=query(k*2,l,r);
	res+=query(k*2+1,l,r);
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=k;i++)
			cin>>q[i].l>>q[i].r>>tt[i];
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++)
			cout<<x[i]<<" ";
		cout<<endl;
		for(int i=1;i<=k;i++)
		{
			l[i]=lower_bound(x+1,x+1+n,l[i])-x;
			r[i]=upper_bound(x+1,x+1+n,r[i])-x-1;
			// cout<<l[i]<<" "<<r[i]<<endl;
		}	
		
		
	}
	
	return 0;
}