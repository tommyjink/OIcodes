#include<bits/stdc++.h>
#define int __int128
#define endl "\n"
using namespace std;
const int N=1e5+10,INF=1e18;
int n,m,k,a[N],b[N],c[N],id[N];
int lazy[N*8];
inline int read()
{
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=res*10+(ch^'0'),ch=getchar();
    return res;
}
inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(int x,int y)
{
    return b[x]+c[x]>b[y]+c[y];
}
struct node
{
    int l,r,val,mx;
}t[N*8];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
    t[k].mx=max(t[k*2].mx,t[k*2+1].mx);
}
void pushdown(int k)
{
    if(~lazy[k])
    {
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        t[k*2].val=lazy[k]*(t[k*2].r-t[k*2].l+1);
        t[k*2+1].val=lazy[k]*(t[k*2+1].r-t[k*2+1].l+1);
        t[k*2].mx=lazy[k];
        t[k*2+1].mx=lazy[k];
        lazy[k]=-1;
    }
}
void build(int k,int l,int r)
{
    lazy[k]=-1;
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[l];
        t[k].mx=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l||l>r)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val=(t[k].r-t[k].l+1)*d;
        t[k].mx=d;
        lazy[k]=d;
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
int fd(int k,int l,int r,int x)
{
    if(t[k].l>r||t[k].r<l||l>r||t[k].mx<x)return 0;
    if(t[k].l==t[k].r)return t[k].l;
    pushdown(k);
    if(t[k*2].mx>=x)return fd(k*2,l,r,x);
    return fd(k*2+1,l,r,x);
}
int queryd(int k,int l,int r,int b,int &need)
{
    if(t[k].l>r||t[k].r<l||l>r)return 0;
    if(l<=t[k].l&&t[k].r<=r)
    {
        int cc=(int)t[k].val-(int)b*(t[k].r-t[k].l+1);
        if(cc<need)
        {
            need-=cc;
            return 0;
        }
        if(t[k].l==t[k].r)return t[k].l;
    }
    pushdown(k);
    int res=queryd(k*2,l,r,b,need);
    if(res)return res;
    return queryd(k*2+1,l,r,b,need);
}

int query(int k,int l,int r,int b,int c)
{
    int need=c;
    return queryd(k,l,r,b,need);
}
int sum(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l||l>r)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return sum(k*2,l,r)+sum(k*2+1,l,r);
}
void solve()
{
    n=read();
    m=read();
    k=read();
    int nn=n;
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=m;i++)
        b[i]=read(),c[i]=read();
    sort(a+1,a+1+n);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int p=0;
        while(!(p=fd(1,1,n,b[i]))||!query(1,p,n,b[i]-1,c[i]))
        {
            if(n==1){cout<<"-1"<<endl;return;}
            // cout<<"!!"<<i<<","<<p<<endl;
            // for(int i=1;i<=n;i++)cout<<sum(1,i,i)<<" ";
            // cout<<endl;
            n--;
            // cout<<sum(1,n,n+1)<<"?"<<endl;
            modify(1,n,n,sum(1,n,n+1)-k);
            modify(1,n+1,n+1,INF);
        }
        int r=query(1,p,n,b[i]-1,c[i]);
        int cost=(int)(c[i]-sum(1,p,r-1)+(r-p)*(b[i]-1));
        modify(1,p,r-1,b[i]-1);
        modify(1,r,r,sum(1,r,r)-cost);
    }
    write(nn-n);
    cout<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int c,t;
    c=read();
    t=read();
    while(t--)solve();
    return 0;
}