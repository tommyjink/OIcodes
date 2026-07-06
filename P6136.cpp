#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(now) t[now].l
#define rs(now) t[now].r
using namespace std;
const int N=1e6+10;
int tot,x,y,z,rt,n,m,a[N];
struct node{int l,r,pri,val,siz;}t[N];
int add(int k){t[++tot]={0,0,rand(),k,1};return tot;}
void pushup(int now){t[now].siz=t[ls(now)].siz+t[rs(now)].siz+1;}
void split(int now,int k,int &x,int &y)
{
	if(!now){x=y=0;return;}
	if(t[now].val<=k)x=now,split(rs(x),k,rs(x),y);
	else y=now,split(ls(y),k,x,ls(y));
	pushup(now);
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(t[x].pri<t[y].pri){rs(x)=merge(rs(x),y);pushup(x);return x;}
	else {ls(y)=merge(x,ls(y));pushup(y);return y;}
}
void ins(int k)
{
	split(rt,k,x,y);
	rt=merge(merge(x,add(k)),y);
}
void del(int k)
{
	split(rt,k,y,z),split(y,k-1,x,y);
	y=merge(ls(y),rs(y));
	rt=merge(merge(x,y),z);
}
int rnk(int k)
{
	split(rt,k-1,x,y);
	int res=t[x].siz+1;
	rt=merge(x,y);
	return res;
}
int kth(int k)
{
	int now=rt;
	while(now)
	{
		int tmp=t[ls(now)].siz+1;
		if(tmp<k)k-=tmp,now=rs(now);
		else if(tmp==k)return t[now].val;
		else now=ls(now);
	}
	return -1;
}
int pre(int k)
{
	split(rt,k-1,x,y);
	int now=x;
	while(rs(now))now=rs(now);
	rt=merge(x,y);
	return t[now].val;
}
int nxt(int k)
{
	split(rt,k,x,y);
	int now=y;
	while(ls(now))now=ls(now);
	rt=merge(x,y);
	return t[now].val;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],ins(a[i]);
	int lst=0,ans=0;
	while(m--)
	{
		int op,x;cin>>op>>x;
		x^=lst;
		if(op==1)ins(x);
		if(op==2)del(x);
		if(op==3)lst=rnk(x),ans^=lst;
		if(op==4)lst=kth(x),ans^=lst;
		if(op==5)lst=pre(x),ans^=lst;
		if(op==6)lst=nxt(x),ans^=lst;
	}
	cout<<ans<<endl;
	return 0;
}