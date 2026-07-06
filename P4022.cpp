#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=11e5+10;
int n,m,len,tot=1,num[N],f[N];
int tmp=1,q[N],pos[N<<1];
char s[N];
queue<int> Q;
struct SAM
{
	int fa,len;
	int ch[5];
}tre[N<<1];
struct Tire
{
	int c,fa;
	int ch[5];
}t[N<<1];
int Tire_insert(int ch,int x)
{
	if(!t[x].ch[ch])t[x].ch[ch]=++tmp,t[tmp].c=ch,t[tmp].fa=x;
	return t[x].ch[ch];
}
int SAM_insert(int c,int las)
{
	int p=las,np=++tot;tre[np].len=tre[p].len+1;
	while(p&&!tre[p].ch[c])tre[p].ch[c]=np,p=tre[p].fa;
	if(!p)tre[np].fa=1;
	else
	{
		int q=tre[p].ch[c];
		if(tre[q].len==tre[p].len+1)tre[np].fa=q;
		else
		{
			int nq=++tot;tre[nq]=tre[q];tre[nq].len=tre[p].len+1;
			tre[q].fa=tre[np].fa=nq;
			while(p&&tre[p].ch[c]==q)tre[p].ch[c]=nq,p=tre[p].fa;
		}
	}
	return np;
}
void SAM_work()
{
	for(int i=0;i<2;i++)if(t[1].ch[i])Q.push(t[1].ch[i]);
	pos[1]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		pos[x]=SAM_insert(t[x].c,pos[t[x].fa]);
		for(int i=0;i<2;i++)if(t[x].ch[i])Q.push(t[x].ch[i]);
	}
}
bool judge(int mid)
{
	int head=1,tail=0;
	for(int i=1;i<=len;i++)
	{
		f[i]=f[i-1];
		if(i<mid)continue;
		while(head<=tail&&f[q[tail]]-q[tail]<=f[i-mid]-(i-mid))tail--;
		q[++tail]=i-mid;
		while(head<=tail&&q[head]<i-num[i])head++;
		if(head<=tail)f[i]=max(f[i],f[q[head]]+i-q[head]);
	}
	return f[len]*10>=len*9;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s+1);int las=1;len=strlen(s+1);
		for(int j=1;j<=len;j++)las=Tire_insert(s[j]-'0',las);
	}
	SAM_work();
	while(n--)
	{
		scanf("%s",s+1);len=strlen(s+1);int p=1,le=0;
		for(int i=1;i<=len;i++)
		{
			int ch=s[i]-'0';
			while(p&&!tre[p].ch[ch])p=tre[p].fa,le=tre[p].len;
			if(tre[p].ch[ch])p=tre[p].ch[ch],le++;
			else p=1,le=0;
			num[i]=le;
		}
		int l=0,r=len;
		while(l<r){int mid=(l+r+1)>>1;if(judge(mid))l=mid;else r=mid-1;}
		printf("%lld\n",l);
	}
	return 0;
}
