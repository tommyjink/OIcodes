#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,tot=0,head[N*2];
int num=0,L[N],R[N];
int id[N],siz[N],m;
int f[N][35],dep[N];
vector<int> sav[N];
struct node
{
	int to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void dfs1(int x,int fa,int d)
{
	L[x]=++num,id[num]=x,dep[num]=d;
	f[x][0]=fa,siz[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x,d+1);
		siz[x]+=siz[v];
	}
	R[x]=num;
}
void initf()
{
	for(int i=1;i<=30;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
}
int findroot(int x,int p)
{
	for(int i=30;i>=0;i--)
	{
		if(p-(1LL<<i)>=0)
		{
			p-=(1LL<<i);
			x=f[x][i];
		}
	}
	return x;
}

signed main()
{
	cin>>n;n++;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;x++;
		add(x,i),add(i,x);
	}
	dfs1(1,0,0);
	for(int i=1;i<=num;i++)
		sav[dep[i]].push_back(i);
	for(int i=0;i<=n;i++)
		if(!sav[i].empty())
			sort(sav[i].begin(),sav[i].end());
	// for(int i=0;i<=n;i++)
		// if(!sav[i].empty())
		// {
			// printf("sav[%lld]:",i);
			// for(int j=0;j<sav[i].size();j++)
			// {
				// printf("%lld ",sav[i][j]);
			// }
			// cout<<endl;
		// }
	initf();
	cin>>m;
	while(m--)
	{
		int x,p;
		cin>>x>>p;x++;
		int rt=findroot(x,p);
		if(rt==0||rt==1)
		{
			cout<<"0"<<" ";
			continue;
		}
		// cout<<"rt:"<<rt<<endl;
		int de=dep[L[rt]]+p;
		// printf("L[rt],R[rt],de:%lld,%lld,%lld\n",L[rt],R[rt],de);
		int p1=lower_bound(sav[de].begin(),sav[de].end(),L[rt])-sav[de].begin();
		int p2=upper_bound(sav[de].begin(),sav[de].end(),R[rt])-sav[de].begin();
		// cout<<p1<<" "<<p2<<endl;
		cout<<p2-p1-1<<" ";
	}
	
	return 0;
}