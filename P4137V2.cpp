#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],cnt=0,rt[N];
struct node
{
    int l,r,val;
}t[N*16];
void pushup(int k)
{
    t[k].val=min(t[t[k].l].val,t[t[k].r].val);
}
int add(int x)
{
    t[++cnt]=t[x];
    return cnt;
}
int build(int l,int r)
{
    int now=++cnt;
    if(l==r)return now;
    int mid=(l+r)>>1;
    t[now].l=build(l,mid);
    t[now].r=build(mid+1,r);
    pushup(now);
    return now;
}
int modify(int now,int l,int r,int x,int d)
{
    now=add(now);
    if(l==r)
    {
        t[now].val=d;
        return now;
    }
    int mid=(l+r)>>1;
    if(x<=mid)t[now].l=modify(t[now].l,l,mid,x,d);
    else t[now].r=modify(t[now].r,mid+1,r,x,d);
    pushup(now);
    return now;
}
int query(int now,int l,int r,int x)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(t[t[now].l].val<x)return query(t[now].l,l,mid,x);
    return query(t[now].r,mid+1,r,x);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    rt[0]=build(0,n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        rt[i]=modify(rt[i-1],0,n+1,a[i],i);
    }
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(rt[r],0,n+1,l)<<endl;
    }
    return 0;
}