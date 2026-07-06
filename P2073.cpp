#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int tot=0,Root=0,num=0;
int vis[N];
struct node
{
	int ch[2];
	int size,pri;
	int c,w,sumc,sumw;
}t[N*2];
int ran()
{
	return rand()%(N-100);
}
int NewNode(int c,int w)
{
	t[++tot].size=1;
	t[tot].pri=ran();
	t[tot].c=t[tot].sumc=c;
	t[tot].w=t[tot].sumw=w;
	return tot;
}
void update(int id)
{
	t[id].size=t[t[id].ch[0]].size+t[t[id].ch[1]].size+1;
	t[id].sumc=t[t[id].ch[0]].sumc+t[t[id].ch[1]].sumc+t[id].c;
	t[id].sumw=t[t[id].ch[0]].sumw+t[t[id].ch[1]].sumw+t[id].w;
}
void split(int id,int val,int &x,int &y)
{
	if(!id){x=y=0;return;}
	if(t[id].c<=val)
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
int Rank(int v)
{
	int x,y;
	split(Root,v,x,y);
	int res=t[x].size;
	Root=merge(x,y);
	return res;
}
int kth(int id,int k)
{
	while(1)
	{
		int lsize=t[t[id].ch[0]].size;
		if(lsize+1==k)return t[id].c;
		else if(lsize>=k)id=t[id].ch[0];
		else id=t[id].ch[1],k-=(lsize+1);
	}
}
void insert(int c,int w)
{
	int x,y,id=NewNode(c,w);
	split(Root,c,x,y);
	Root=merge(merge(x,id),y);
}
void del(int v)
{
	int x,y,a,b;
	split(Root,v,x,y);
	split(x,v-1,a,b);
	Root=merge(a,y);
}

signed main()
{
	while(1)
	{
		int ch;cin>>ch;
		if(ch==-1)
		{
			cout<<t[Root].sumw<<" "<<t[Root].sumc<<endl;
			return 0;
		}
		if(ch==1)
		{
			int w,c;
			cin>>w>>c;
			if(vis[c])continue;
			vis[c]=true,num++;
			insert(c,w);
		}
		if(ch==2)
		{
			if(!num)continue;
			int c=kth(Root,num);
			vis[c]=false;
			del(c);
			num--;
		}
		if(ch==3)
		{
			if(!num)continue;
			int c=kth(Root,1);
			vis[c]=false;
			del(c);
			num--;
		}
	}
	
	// while(1)
	// {
		// for(int i=1;i<=num;i++)
			// cout<<kth(Root,i)<<" ";
		// cout<<endl;
		// int ch;cin>>ch;
		// if(ch==1)
		// {
			// int x;cin>>x;
			// insert(x,1);num++;
		// }
	// }
	return 0;
}