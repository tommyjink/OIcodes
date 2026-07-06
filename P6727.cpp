#include<bits/stdc++.h>
#include<stdio.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3000010,M=100010;
const int Base=193,Mod=998244353,Base1=131,Mod1=19260817;
int n,q,ch[N][26],tot=1,ql[N],qr[N],nowid;
char s[N];
string a[M],b[M],ss;
struct Node
{
	int hsh1,hsh2;
	bool operator < (const Node &x) const
	{
		if(hsh1==x.hsh1)return hsh2<x.hsh2;
		return hsh1<x.hsh1;
	}
}hsh[N];
vector<Node> p[N];
set<Node> suf;
map<Node,vector<int> > g;
void insert(char *s,int len)
{
	int x=1;
	p[x].push_back(hsh[0]);
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(!ch[x][c])ch[x][c]=++tot;
		x=ch[x][c];
		p[x].push_back(hsh[i+1]);
	}
}
void dfs(int x)
{
	ql[x]=++nowid;
	for(int i=0;i<p[x].size();i++)
		if(suf.count(p[x][i]))g[p[x][i]].push_back(ql[x]);
	for(int i=0;i<26;i++)
		if(ch[x][i])dfs(ch[x][i]);
	qr[x]=++nowid;
}
int ask(string s,Node w)
{
	int x=1;
	for(int i=0;i<s.size();i++)x=ch[x][s[i]-'a'];
	return upper_bound(g[w].begin(),g[w].end(),qr[x])-lower_bound(g[w].begin(),g[w].end(),ql[x]);
}
Node calc(string s)
{
	int x=0,y=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		x=(x*Base%Mod+s[i]-'a'+1)%Mod;
		y=(y*Base1%Mod1+s[i]-'a'+1)%Mod1;
	}
	return (Node){x,y};
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int len=strlen(s);
		hsh[len]=(Node){0,0};
		for(int j=len-1;j>=0;j--)
		{
			hsh[j].hsh1=(hsh[j+1].hsh1*Base%Mod+s[j]-'a'+1)%Mod;
			hsh[j].hsh2=(hsh[j+1].hsh2*Base1%Mod1+s[j]-'a'+1)%Mod1;
		}
		insert(s,len);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ss;
		int pos=ss.find('*');
		a[i]=ss.substr(0,pos);
		b[i]=ss.substr(pos+1);
		suf.insert(calc(b[i]));
	}
	dfs(1);
	for(int i=1;i<=q;i++)cout<<ask(a[i],calc(b[i]))<<endl;
	return 0;
}
