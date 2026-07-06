#include<bits/stdc++.h>
using namespace std;
const int N=100;
char ss[N];
int s[N],n,k;
struct node
{
	int len,val[N];
}ans,sv[N][N];
inline void scan(node &x)
{
	string s;
	cin>>s;
	x.len=s.length();
	for(int i=x.len-1;i>=0;i--)
		x.val[x.len-i]=s[i]-'0';
}
inline void print(node x)
{
	for(int i=x.len;i>=1;i--)
		cout<<x.val[i];
	cout<<endl;
}
node operator +(const node &a,const node &b)
{
	int len=max(a.len,b.len),tag=0;
	node res=(node){len,{0}};
	for(int i=1;i<=len;i++)
	{
		res.val[i]=a.val[i]+b.val[i]+tag;
		tag=res.val[i]/10;
		res.val[i]%=10;
	}
	if(tag)res.val[++res.len]=1;
	return res;
}
node operator *(const node &a,const int &b)
{
	node res=(node){1,{0}},aa=a;
	int bb=b;
	while(bb)
	{
		if(bb&1)res=res+aa;
		bb>>=1;
		aa=aa+aa;
	}
	return res;
}
node operator *(const node &a,const node &b)
{
	node res=(node){1,{0}};
	for(int i=1;i<=a.len;i++)
	{
		node p=b*a.val[i];
		for(int j=2;j<=i;j++)p=p*10;
		res=res+p;
	}
	return res;
}
bool operator >(const node &a,const node &b)
{
	if(a.len!=b.len)return a.len>b.len;
	for(int i=a.len;i>=1;i--)
		if(a.val[i]!=b.val[i])
			return a.val[i]>b.val[i];
	return 0;
}
node n_max(node a,node b){return a>b?a:b;}
void dfs(int pos,int num,int tot,node cnt)
{
	if(sv[pos-1][num-1]>cnt)return;
	sv[pos-1][num-1]=cnt;
	if(num==tot+1&&pos==n+1)
	{ans=n_max(ans,cnt);return;}
	if(pos>=n+1)return;
	if(num>=tot+1)return;
	node tmp=(node){0,{0}};
	for(int i=pos;i<=n-(tot-num);i++)
	{
		tmp.val[++tmp.len]=s[i];
		dfs(i+1,num+1,tot,cnt*tmp);
	}
}
signed main()
{
	cin>>n>>k;
	for(int i=n;i>=1;i--)cin>>ss[i];
	for(int i=n;i>=1;i--)s[i]=ss[i]-'0';
	ans.len=1,ans.val[0]=0;
	dfs(1,1,k+1,(node){1,{0,1}});
	print(ans);
	return 0;
}