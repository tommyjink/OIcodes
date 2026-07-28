#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(k) t[k].l
#define rs(k) t[k].r
using namespace std;
const int N=2e6+10;
int n,p[N],id[N],fa[N],m,tot,root[N];
struct node
{
    int l,r,sum=0;
}t[N*4];
int getfa(int x)
{
    if(x==fa[x])return x;
    return fa[x]=getfa(fa[x]);
}
void pushup(int k)
{
    t[k].sum=t[ls(k)].sum+t[rs(k)].sum;
}
void insert(int &k,int l,int r,int x)
{
    if(!k)k=++tot;
    if(l==r){t[k].sum++;return;}
    int mid=(l+r)>>1;
    if(x<=mid)insert(ls(k),l,mid,x);
    else insert(rs(k),mid+1,r,x);
    pushup(k);
}
int query(int k,int l,int r,int x)
{
    if(t[k].sum<x)return 0;
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(t[ls(k)].sum>=x)return query(ls(k),l,mid,x);
    else return query(rs(k),mid+1,r,x-t[ls(k)].sum);
}
int merge(int l,int r,int x,int y)
{
    if(!x||!y)return x+y;
    if(l==r)
    {
        t[x].sum+=t[y].sum;
        return x;
    }
    int mid=(l+r)>>1;
    ls(x)=merge(l,mid,ls(x),ls(y));
    rs(x)=merge(mid+1,r,rs(x),rs(y));
    pushup(x);
    return x;
}
void con(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return;
    fa[x]=y;
    root[y]=merge(1,n,root[x],root[y]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        id[p[i]]=i;
        fa[i]=i;
        insert(root[i],1,n,p[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        con(x,y);
    }
    id[0]=-1;
    int q;cin>>q;
    while(q--)
    {
        char op;int x,y;
        cin>>op>>x>>y;
        if(op=='Q')cout<<id[query(root[getfa(x)],1,n,y)]<<endl;
        else con(x,y);
    }
    return 0;
}