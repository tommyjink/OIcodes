#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,tot=0,head[N*2];
int cc[N],dep[N],siz[N];
int son[N],L[N],R[N],num=0;
int id[N],c[N],qx[N],qdep[N];
int cnt[N]['z'-'a'+5],ct[N];
int ans[N],t[N];
vector<int> qid[N];
struct node
{
	int to,next;
}e[N*2];
void addedge(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void add(int x)
{
	cnt[dep[x]][c[x]]++;
	if(cnt[dep[x]][c[x]]&1)
		ct[dep[x]]++;
	else ct[dep[x]]--;
}
void del(int x)
{
	cnt[dep[x]][c[x]]--;
	if(cnt[dep[x]][c[x]]&1)
		ct[dep[x]]++;
	else ct[dep[x]]--;
}
void dfs1(int x,int fa,int d)
{
	siz[x]=1,son[x]=0;
	L[x]=++num,id[num]=x;
	c[num]=cc[x],dep[num]=d;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x,d+1);
		siz[x]+=siz[v];
		if(!son[x]||siz[v]>siz[son[x]])
			son[x]=v;
	}
	R[x]=num;
}
void dfs2(int x,int fa,bool keep)
{
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||v==son[x])continue;
		dfs2(v,x,false);
	}
	if(son[x])dfs2(son[x],x,true);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||v==son[x])continue;
		for(int j=L[v];j<=R[v];j++)
			add(j);
	}
	add(L[x]);
	for(int i=0;i<(int)qid[x].size();i++)
		if(ct[qdep[qid[x][i]]]<=1)ans[qid[x][i]]=1;
		else ans[qid[x][i]]=0;
	if(!keep)
		for(int i=L[x];i<=R[x];i++)
			del(i);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		addedge(x,i);
		addedge(i,x);
	}
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		cc[i]=s[i-1]-'a';
	for(int i=1;i<=m;i++)
	{
		cin>>qx[i]>>qdep[i];
		qid[qx[i]].push_back(i);
	}
	dfs1(1,0,1);
	dfs2(1,0,true);
	// for(int i=1;i<=n;i++)
		// cout<<dep[L[i]]<<" ";
	// cout<<endl;
	for(int i=1;i<=m;i++)
		if(ans[i])cout<<"Yes\n";
		else cout<<"No\n";
	return 0;
}