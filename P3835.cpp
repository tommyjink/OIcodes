#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
const int E1=-(1LL<<31)+1;
const int E2=(1LL<<31)-1;
int n,root[N],tot=0;
struct node
{
	int ch[2],val,size,pri;
}t[N*51];
int ran()
{
	return rand()%(N-10);
}
int NewNode(int val)
{
	t[++tot].val=val;
	t[tot].size=1;
	t[tot].pri=ran();
	return tot;
}
void update(int id)
{
	t[id].size=t[t[id].ch[0]].size+t[t[id].ch[1]].size+1;
}
void split(int id,int val,int &x,int &y)
{
	if(!id){x=y=0;return;}
	if(t[id].val<=val)
	{
		x=NewNode(t[id].val);
		t[x]=t[id];
		split(t[x].ch[1],val,t[x].ch[1],y);
		update(x);
	}
	else
	{
		y=NewNode(t[id].val);
		t[y]=t[id];
		split(t[y].ch[0],val,x,t[y].ch[0]);
		update(y);
	}
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(t[x].pri<t[y].pri)
	{
		int id=NewNode(0);
		t[id]=t[x];
		t[id].ch[1]=merge(t[id].ch[1],y);
		update(id);
		return id;
	}
	else
	{
		int id=NewNode(0);
		t[id]=t[y];
		t[id].ch[0]=merge(x,t[id].ch[0]);
		update(id);
		return id;
	}
}
int kth(int id,int k)
{
	while(1)
	{
		int lsize=t[t[id].ch[0]].size;
		if(lsize+1==k)return t[id].val;
		else if(lsize>=k)id=t[id].ch[0];
		else id=t[id].ch[1],k-=lsize+1;
	}
}
signed main()
{
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp,opt,v;
		cin>>tmp>>opt>>v;
		root[i]=root[tmp];
		if(opt==1)
		{
			int x,y,id=NewNode(v);
			split(root[i],v,x,y);
			root[i]=merge(merge(x,id),y);
		}
		if(opt==2)
		{
			int x,y,z;
			split(root[i],v,x,z);
			split(x,v-1,x,y);
			y=merge(t[y].ch[0],t[y].ch[1]);
			root[i]=merge(merge(x,y),z);
		}
		if(opt==3)
		{
			int x,y;
			split(root[i],v-1,x,y);
			cout<<t[x].size+1<<endl;
			root[i]=merge(x,y);
		}
		if(opt==4)
		{
			cout<<kth(root[i],v)<<endl;		
		}
		if(opt==5)
		{
			int x,y;
			split(root[i],v-1,x,y);
			if(x==0)cout<<E1<<endl;
			else cout<<kth(x,t[x].size)<<endl;
			root[i]=merge(x,y);
		}
		if(opt==6)
		{
			int x,y;
			split(root[i],v,x,y);
			if(y==0)cout<<E2<<endl;
			else cout<<kth(y,1)<<endl;
			root[i]=merge(x,y);
		}
	}
	return 0;
}