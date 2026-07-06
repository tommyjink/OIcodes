#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+30;
int n,m,cc[N],head[N],tot=0;
int snum=0,qk[N],siz[N],dep[N];
int id[N],num=0,L[N],R[N],son[N];
int c[N],col[N],ccol[N],ctot=0;
int cnt[N],ans[N];
vector<int> qid[N];
map<string,int> mp;
struct node
{
	int to,next;
}e[N*2];
struct point
{
	int c,dep,num;
}p[N];
bool cmp(point x,point y)
{
	return x.dep==y.dep?x.c<y.c:x.dep<y.dep;
}
void addedge(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void add(int x)
{
	ccol[col[x]]++;
	if(ccol[col[x]]==1)
		cnt[dep[x]]++;
}
void del(int x)
{
	if(ccol[col[x]]==1)
		cnt[dep[x]]--;
	ccol[col[x]]--;
}
void dfs1(int x,int fa,int d)
{
	siz[x]=1,L[x]=++num,dep[num]=d;
	id[num]=x,c[num]=cc[x];
	p[num]=(point){c[num],dep[num],num};
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
		ans[qid[x][i]]=cnt[qk[qid[x][i]]+dep[L[x]]];
	if(!keep)
		for(int i=L[x];i<=R[x];i++)
			del(i);
}
signed main()
{
	cin>>n;n++;
	for(int i=2;i<=n;i++)
	{
		string s;
		int x;
		cin>>s>>x;
		x++;
		addedge(x,i);
		addedge(i,x);
		if(mp[s])cc[i]=mp[s];
		else cc[i]=mp[s]=++snum;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		x++;
		qk[i]=y;
		qid[x].push_back(i);
	}
	dfs1(1,0,1);
	sort(p+1,p+1+n,cmp);
	// for(int i=1;i<=n;i++)
		// printf("%lld:%lld %lld %lld\n",id[p[i].num],p[i].c,p[i].dep,p[i].num);
	for(int i=1;i<=n;i++)
		if(p[i].dep==p[i-1].dep&&p[i].c==p[i-1].c)
			col[p[i].num]=col[p[i-1].num];
		else col[p[i].num]=++ctot;
	dfs2(1,0,true);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}