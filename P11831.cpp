#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=100000,M=64;
int n,m,q,a[N],rk[N],b[N],bk[N];
vector<int> tr[N];
bitset<N> bn[N],A[M],B[M],cur;
int rd()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')x=x*10+(c&15),c=getchar();
	return x;
}
void wt(int x)
{
	if(x>9)wt(x/10);
	putchar(x%10|48);
}
void aupd(int k,int l,int r,int p,int id,bool add)
{
	add?A[k].set(id):A[k].reset(id);
	if(r-l==1||k>=32)return;
	int mid=(l+r+1)>>1;
	aupd(k<<1|(p>=mid),p<mid?l:mid,p<mid?mid:r,p,id,add);
}
void aask(int k,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r){cur|=A[k];return;}
	if(k>=32)
	{
		for(int i=max(l,ql);i<min(r,qr);i++)cur.set(rk[i]);
		return;
	}
	int mid=(l+r+1)>>1;
	if(ql<mid)aask(k<<1,l,mid,ql,qr);
	if(qr>mid)aask(k<<1|1,mid,r,ql,qr);
}
void bupd(int k,int l,int r,int p,int id,bool add)
{
	add?B[k].set(id):B[k].reset(id);
	if(r-l==1||k>=32)return;
	int mid=(l+r+1)>>1;
	bupd(k<<1|(p>=mid),p<mid?l:mid,p<mid?mid:r,p,id,add);
}
int bask(int k,int l,int r)
{
	if(r-l==1||k>=32)
	{
		for(int i=r-1;i>=l;i--)
			if(cur[bk[i]])return i+1;
		return l;
	}
	int mid=(l+r+1)>>1;
	return(cur&B[k<<1|1]).any()?bask(k<<1|1,mid,r):bask(k<<1,l,mid);
}
void test(int l,int r)
{
    int cut=1,mid=(l+r+1)>>1;
    if(r-l==1)
    {
        for(int i=l;i<=r;i++)
        {
            if(cur[bk[i]])return;
        }
        return;
    }
    int mid=(l+r+1)>>1;
    return cur&(1ll<<n);
}
void sol()
{
	n=rd(),m=rd(),q=rd();
	for(int i=0;i<n;i++)tr[i].clear(),bn[i].reset();
	for(int i=0;i<m;i++)
	{
		int u=rd()-1,v=rd()-1;
		tr[u].push_back(v);
	}
	for(int u=n-1;u>=0;u--)
	{
		bn[u].set(u);
		for(int v:tr[u])bn[u]|=bn[v];
	}
	for(int i=0;i<n;i++)rk[a[i]=rd()-1]=i;
	for(int i=0;i<n;i++)bk[b[i]=rd()-1]=i;
	for(int i=1;i<M;i++)A[i].reset(),B[i].reset();
	for(int i=0;i<n;i++)
		aupd(1,0,n,a[i],i,1),bupd(1,0,n,b[i],i,1);
	while(q--)
	{
		int op=rd();
		if(op==1)
		{
			int x=rd()-1,y=rd()-1;
			if(x==y)continue;
			aupd(1,0,n,a[x],x,0),aupd(1,0,n,a[y],y,0);
			swap(a[x],a[y]),rk[a[x]]=x,rk[a[y]]=y;
			aupd(1,0,n,a[x],x,1),aupd(1,0,n,a[y],y,1);
		}
		else if(op==2)
		{
			int x=rd()-1,y=rd()-1;
			if(x==y)continue;
			bupd(1,0,n,b[x],x,0),bupd(1,0,n,b[y],y,0);
			swap(b[x],b[y]),bk[b[x]]=x,bk[b[y]]=y;
			bupd(1,0,n,b[x],x,1),bupd(1,0,n,b[y],y,1);
		}
		else
		{
			int x=rd()-1,l=rd()-1,r=rd();
			cur.reset();
			aask(1,0,n,l,r);
			cur&=bn[x];
			if(cur.any())wt(bask(1,0,n));
			else putchar('0');
			putchar('\n');
		}
	}
}
signed main()
{
	int c=rd(),T=rd();
	while(T--)sol();
	return 0;
}
