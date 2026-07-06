#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,tot=0,Root=0,num=0,ans=0;
struct node
{
	int val,num;
}a[N];
bool cmp(node x,node y)
{
	return x.val==y.val?x.num<y.num:x.val>y.val;
}
int ran()
{
	return rand()%(N-100);
}
struct Node
{
	int ch[2],val,size,pri;
}t[N*2];
void update(int id)
{
	t[id].size=t[t[id].ch[0]].size+t[t[id].ch[1]].size+1;
}
int NewNode(int val)
{
	t[++tot].size=1;
	t[tot].val=val;
	t[tot].pri=ran();
	return tot;
}
void split(int id,int val,int &x,int &y)
{
	if(!id){x=y=0; return;}
	if(t[id].val<=val)
	{
		x=id;
		split(t[id].ch[1],val,t[id].ch[1],y);
	}
	else
	{
		y=id;
		split(t[id].ch[0],val,x,t[id].ch[0]);
	}
	update(id);
	return;
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(t[x].pri<t[y].pri)
	{
		t[x].ch[1]=merge(t[x].ch[1],y);
		update(x); return x;
	}
	else
	{
		t[y].ch[0]=merge(x,t[y].ch[0]);
		update(y); return y;
	}
}
int Rank(int val)
{
	int x,y;
	split(Root,val,x,y);
	int res=t[x].size;
	Root=merge(x,y);
	return res;
}
int kth(int id,int k)
{
	while(1)
	{
		int lsize=t[t[id].ch[0]].size;
		if(lsize+1==k)return t[id].val;
		else if(lsize>=k)id=t[id].ch[0];
		else id=t[id].ch[1],k-=(lsize+1);
	}
}
void insert(int val)
{
	++num;
	int x,y,id=NewNode(val);
	split(Root,val,x,y);
	Root=merge(merge(x,id),y);
}
int lst(int val)
{
	int rk=Rank(val);
	if(rk==1)return 1;
	else return kth(Root,rk-1)+1;
}
int nxt(int val)
{
	int rk=Rank(val);
	if(rk==num)return n;
	else return kth(Root,rk+1)-1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(NULL));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val;
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=n;
		insert(a[i].num);
		l=lst(a[i].num);
		r=nxt(a[i].num);
		ans+=(r-a[i].num+1)*(a[i].num-l+1)*a[i].val;
	}
	Root=0,num=0;
	for(int i=n;i>=1;i--)
	{
		int l=1,r=n;
		insert(a[i].num);
		l=lst(a[i].num);
		r=nxt(a[i].num);
		ans-=(r-a[i].num+1)*(a[i].num-l+1)*a[i].val;
	}
	cout<<ans;
	return 0;
}