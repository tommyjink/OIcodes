#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,a[N],lazy[N*4],op[N],l[N],r[N],q,b[N];
struct node
{
    int l,r,val;
}t[N*4];
void pushdown(int k)
{
    if(lazy[k]==1)
    {
        t[k*2].val=t[k*2].r-t[k*2].l+1;
        t[k*2+1].val=t[k*2+1].r-t[k*2+1].l+1;
        lazy[k*2]=lazy[k*2+1]=1;
        lazy[k]=0;
    }
    else if(lazy[k]==2)
    {
        t[k*2].val=t[k*2+1].val=0;
        lazy[k*2]=lazy[k*2+1]=2;
        lazy[k]=0;
    }
}
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void build(int k,int l,int r)
{
    lazy[k]=0;
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int mode)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(mode==1)t[k].val=t[k].r-t[k].l+1;
        if(mode==2)t[k].val=0;
        lazy[k]=mode;
        return;
    }
    pushdown(k);
    modify(k*2,l,r,mode);
    modify(k*2+1,l,r,mode);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query(k*2,l,r)+query(k*2+1,l,r);
}
bool check(int x)
{
    for(int i=1;i<=n;i++)
        b[i]=(a[i]>=x);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int sum=query(1,l[i],r[i]);
        if(op[i]==0)
        {
            modify(1,r[i]-sum+1,r[i],1);
            modify(1,l[i],r[i]-sum,2);
        }
        if(op[i]==1)
        {
            modify(1,l[i],l[i]+sum-1,1);
            modify(1,l[i]+sum,r[i],2);
        }
    }
    return bool(query(1,q,q));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>op[i]>>l[i]>>r[i];
    cin>>q;
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}