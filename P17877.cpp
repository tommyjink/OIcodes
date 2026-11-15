#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,k,a[N],b[N],c[N],id[N];
int lazy[N*8];
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
}
void pushdown(int k)
{
    if(~lazy[k])
    {
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        t[k*2].val=lazy[k]*(t[k*2].r-t[k*2].l+1);
        t[k*2+1].val=lazy[k]*(t[k*2+1].r-t[k*2+1].l+1);
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
        t[k].mx=a[l]
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val=(t[k].r-t[k].l+1)*d;
        lazy[k]=d;
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}

int query(int k,int l,int r,int b,int c)
{
    if(t[k].l>r||t[k].r<l||t[k].val-b*(t[k].r-t[k].l+1)<c)return 0;
    pushdown(k);
    int tmp=t[k*2].val-b*(t[k*2].r-t[k*2].l+1);
    if(tmp>=c)
        return query(k*2,l,r,b,c);
    else return query(k*2+1,l,r,b,c-tmp);
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i]>>c[i],id[i]=i;
    sort(a+1,a+1+n);
    sort(id+1,id+1+m,cmp);
    build(1,1,n);
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    build(1,1,n);
    while(1)
    {
        int op;
        cin>>op;
        if(op==1)
        {

        }
    }
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}