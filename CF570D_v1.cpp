#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,tot=0,head[N*2];
int cc[N],num=0,dep[N];
int id[N],L[N],R[N],c[N];
int cnt['z'-'a'+5];
vector<int> sav[N];
vector<int> sum[N]['z'-'a'+5];
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
	// cout<<x<<endl;
	L[x]=++num,id[num]=x;
	dep[num]=d,c[num]=cc[x];
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x,d+1);
	}
	R[x]=num;
}
signed main()
{
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		add(i,x),add(x,i);
	}
	string s;cin>>s;
	for(int i=1;i<=n;i++)
		cc[i]=s[i-1]-'a';
	dfs1(1,0,1);
	// for(int i=1;i<=n;i++)
		// cout<<id[i]<<" ";
	// cout<<endl;
	for(int i=1;i<=n;i++)
		sav[dep[i]].push_back(i);
	for(int i=0;i<=n;i++)
		if(!sav[i].empty())
			sort(sav[i].begin(),sav[i].end());
	for(int i=0;i<=n;i++)
		if(!sav[i].empty())
		{
			for(int j=0;j<(int)sav[i].size();j++)
				for(int k=0;k<='z'-'a';k++)
				{
					sum[i][k].push_back(0);
					if(j!=0)sum[i][k][j]=sum[i][k][j-1];
					if(c[sav[i][j]]==k)sum[i][k][j]++;
				}	
		}
	// for(int i=0;i<=n;i++)
		// if(!sav[i].empty())
		// {
			// printf("sav[%lld]:",i);
			// for(int j=0;j<(int)sav[i].size();j++)
				// cout<<char(c[sav[i][j]]+'a')<<" ";
				// // cout<<sum[i][c[sav[i][j]]][j]<<" ";
			// cout<<endl;
		// }
	while(m--)
	{
		memset(cnt,0,sizeof(cnt));
		int v,h,ct=0;
		cin>>v>>h;
		int p1=lower_bound(sav[h].begin(),sav[h].end(),L[v])-sav[h].begin();
		int p2=upper_bound(sav[h].begin(),sav[h].end(),R[v])-sav[h].begin()-1;
		// printf("p1:%lld,p2:%lld\n",p1,p2);
		// for(int i=p1;i<=p2;i++)
			// cout<<id[sav[h][i]]<<" ";
		// cout<<endl;
		for(int i=0;i<='z'-'a';i++)
			cnt[i]=sum[h][i][p2]-(p1==0?0:sum[h][i][p1-1]);
		for(int i=0;i<='z'-'a';i++)
			if(cnt[i]&1)ct++;
		if(ct>1)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}