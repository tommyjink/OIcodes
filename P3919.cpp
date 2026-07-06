#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,m,a[N],tot=0,root[N];
struct node
{
    int l,r,val;
}t[N*30];
int add(int k)
{
    t[++tot]=t[k];
    return tot;
}
int build(int k,int l,int r)
{
    k=++tot;
    if(l==r)
    {
        t[k].val=a[l];
        return k;
    }
    int mid=(l+r)>>1;
    t[k].l=build(t[k].l,l,mid);
    t[k].r=build(t[k].r,mid+1,r);
    return k;
}
int modify(int k,int l,int r,int x,int d)
{
    k=add(k);
    if(l>x||r<x)return k;
    if(l==r)
    {
        t[k].val=d;
        return k;
    }
    int mid=(l+r)>>1;
    if(x<=mid)t[k].l=modify(t[k].l,l,mid,x,d);
    else t[k].r=modify(t[k].r,mid+1,r,x,d);
    return k;
}
int query(int k,int l,int r,int x)
{
    if(l==r)return t[k].val;
    int mid=(l+r)>>1;
    if(x<=mid)return query(t[k].l,l,mid,x);
    else return query(t[k].r,mid+1,r,x);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    root[0]=build(root[0],1,n);
    for(int i=1;i<=m;i++)
    {
        int op,v;
        cin>>v>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            root[i]=modify(root[v],1,n,x,y);
        }
        else
        {
            int x;
            cin>>x;
            root[i]=root[v];
            cout<<query(root[i],1,n,x)<<endl;
        }
    }
    return 0;
}