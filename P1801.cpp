#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6;
int n, m, tot=0, Root=0;
int a[N] ,done=0, num=0;
struct node
{
	int siz, val;
	int ch[2], rnd;
}t[N];
int ran()
{
	return rand()%((int)1e6);
}
int newNode(int v)
{
	t[++tot].siz = 1;
	t[tot].rnd = ran();
	t[tot].val = v;
	return tot;
}
void update(int x)
{
	t[x].siz  = t[t[x].ch[0]].siz  + t[t[x].ch[1]].siz + 1;
}
void split(int id, int val, int &x, int &y)
{
	if(!id) {x = y = 0; return;}
	if(t[id].val < val)
	{
		x = id;
		split(t[id].ch[1], val, t[id].ch[1], y);
	}
	else
	{
		y = id;
		split(t[id].ch[0], val, x, t[id].ch[0]);
	}
	update(id);
}
int merge(int x, int y)
{
	if(!x || !y) return x + y;
	if(t[x].rnd < t[y].rnd)
	{
		t[x].ch[1] = merge(t[x].ch[1], y);
		update(x); return x;
	}
	else
	{
		t[y].ch[0] = merge(x, t[y].ch[0]);
		update(y); return y;
	}
}
void insert(int v)
{
	int id = newNode(v);
	int x, y;
	split(Root, v, x, y);
	Root = merge(merge(x, id), y);
}
int kth(int id, int k)
{
	while(1)
	{
		// cout<<id<<endl;
		int lsize = t[t[id].ch[0]].siz;
		if(lsize + 1 == k) return t[id].val;
		else if(lsize >= k) id = t[id].ch[0];
		else k -= lsize + 1, id = t[id].ch[1];
	}
}
signed main()
{
	srand(time(NULL));
	cin >> n >> m;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		int x; cin >> x;
		for(int j = done + 1; j <= x; j++)
		{
			insert(a[j]);
			done = j;
		}
		cout << kth(Root, i) << endl;
	}
	return 0;
}