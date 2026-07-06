#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,tag[N],ans[N],siz[N],fa[N];
pii a[N],q[N];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	if(x==y)return;
	siz[x]+=siz[y];
	fa[y]=x;
}
int cal(int x)
{
	x=getfa(x);
	return siz[x]*(siz[x]+1)/2;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].first,a[i].second=i,fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
		cin>>q[i].first,q[i].second=i;
	sort(a+1,a+1+n);
	sort(q+1,q+1+m);
	int now=1,ansnow=0;
	for(int i=1;i<=m;i++)
	{
		//~ cout<<q[i].first<<","<<q[i].second<<endl;
		while(now<=n&&a[now].first<=q[i].first)
		{
			int id=a[now].second;
			ansnow+=cal(id);
			if(tag[id-1])
			{
				ansnow-=cal(id);
				ansnow-=cal(id-1);
				merge(id-1,id);
				ansnow+=cal(id);
			}
			if(tag[id+1])
			{
				ansnow-=cal(id);
				ansnow-=cal(id+1);
				merge(id+1,id);
				ansnow+=cal(id);
			}
			tag[id]=true;
			now++;
		}
		ans[q[i].second]=ansnow;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
