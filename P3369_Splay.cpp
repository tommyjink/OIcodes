#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,tot=0,Root=0;
struct node
{
	int ch[2],size,fa,val;
}t[N];
#define ls(x) t[(x)].ch[0]
#define rs(x) t[(x)].ch[1]
#define fa(x) t[(x)].fa
int NewNode(int val){t[++tot].val=val;t[tot].size=1;return tot;}
void pushup(int x){t[x].size=t[ls(x)].size+t[rs(x)].size+1;}
void clear(int x){ls(x)=rs(x)=fa(x)=t[x].size=t[x].val=0;}
bool get(int x){return x==rs(fa(x));}
void rotate(int x)
{
	int y=fa(x),z=fa(y),c=get(x),cc=get(y);
	if(t[x].ch[!c])fa(t[x].ch[!c])=y;
	t[y].ch[c]=t[x].ch[!c],t[x].ch[!c]=y;
	fa(y)=x,fa(x)=z;
	if(z)t[z].ch[cc]=x;
	pushup(x),pushup(y);
}
void splay(int x)
{
	for(int f=fa(x);f;rotate(x),f=fa(x))
		if(fa(f))rotate(get(x)==get(f)?f:x);
	Root=x;
}
void insert(int val)
{
	int x=Root,f=0;
	while(x)f=x,x=t[x].ch[val>t[x].val];
	x=NewNode(val),fa(x)=f;
	t[f].ch[val>t[f].val]=x;
	splay(x);
}
void del(int val)
{
	int x=Root,f=0;
	while(t[x].val!=val&&x)
		f=x,x=t[x].ch[val>t[x].val];
	if(!x){splay(f);return;}
	splay(x);int cur=ls(x);
	if(!cur){Root=rs(x),fa(rs(x))=0,clear(x);return;}
	while(rs(cur))x=rs(cur);
	rs(cur)=rs(x),fa(rs(x))=cur,fa(ls(x))=0,clear(x);
	pushup(cur),splay(cur);
}
int Rank(int val)
{
	int res=1,x=Root,p;
	while(x&&p=x)
		
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}