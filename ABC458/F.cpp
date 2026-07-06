#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=120,P=998244353;
int n,k,tot,sz;
int ch[N][26],fail[N],bad[N],id[N];
string s;
struct mat
{
	int a[N][N];
};
void insert(string s)
{
	int u=0;
	for(char c:s)
	{
		int x=c-'a';
		if(!ch[u][x])ch[u][x]=++tot;
		u=ch[u][x];
	}
	bad[u]=1;
}
void build()
{
	queue<int> q;
	for(int i=0;i<26;i++)
		if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		bad[u]|=bad[fail[u]];
		for(int i=0;i<26;i++)
		{
			int v=ch[u][i];
			if(v)fail[v]=ch[fail[u]][i],q.push(v);
			else ch[u][i]=ch[fail[u]][i];
		}
	}
}
mat mul(mat x,mat y)
{
	mat z;
	memset(z.a,0,sizeof(z.a));
	for(int i=0;i<sz;i++)
		for(int k=0;k<sz;k++)
			if(x.a[i][k])
				for(int j=0;j<sz;j++)
					z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j])%P;
	return z;
}
mat qpow(mat x,int y)
{
	mat res;
	memset(res.a,0,sizeof(res.a));
	for(int i=0;i<sz;i++)res.a[i][i]=1;
	while(y)
	{
		if(y&1)res=mul(res,x);
		x=mul(x,x);
		y>>=1;
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>s,insert(s);
	build();
	for(int i=0;i<=tot;i++)
		if(!bad[i])id[i]=sz++;
	mat a;
	memset(a.a,0,sizeof(a.a));
	for(int i=0;i<=tot;i++)
	{
		if(bad[i])continue;
		for(int j=0;j<26;j++)
		{
			int v=ch[i][j];
			if(!bad[v])a.a[id[i]][id[v]]++;
		}
	}
	a=qpow(a,n);
	int ans=0;
	for(int i=0;i<sz;i++)ans=(ans+a.a[id[0]][i])%P;
	cout<<ans<<endl;
	return 0;
}
