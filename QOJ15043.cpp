#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,a[N],l[N],r[N],fa[N],mx[N];
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=mx[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return ;
    if(t[k].l==t[k].r)
    {
        t[k].val=d;
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    return query(k*2,l,r)+query(k*2+1,l,r);
}
void upd(int x)
{
    modify(1,x,mx[x]);
    // cout<<x<<","<<mx[x]<<endl;
    while(fa[x])
    {
        x=fa[x];
        mx[x]=max(a[l[x]],a[r[x]]);
        a[x]=min(a[l[x]],a[r[x]]);
        modify(1,x,mx[x]);
        // cout<<x<<","<<mx[x]<<"|"<<l[x]<<".."<<r[x]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],mx[i]=a[i];
    for(int i=1;i<=n-1;i++)
    {
        a[i+n]=min(a[i*2-1],a[i*2]);
        mx[i+n]=max(a[i*2-1],a[i*2]);
        l[i+n]=i*2-1;
        r[i+n]=i*2;
        fa[i*2-1]=fa[i*2]=i+n;
    }
    build(1,1,n*2-1);
    while(m--)
    {
        char op;int x,y;
        cin>>op>>x>>y;
        if(op=='C')
        {
            swap(a[x],a[y]);
            swap(mx[x],mx[y]);
            upd(x);
            upd(y);
        }
        else
        {
            cout<<query(1,x+n,y+n)<<endl;
        }
    }
    return 0;
}