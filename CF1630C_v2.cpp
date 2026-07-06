#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],f[N],b[N];
//f[i]=min(f[j]+1),j=[min(i-1,b[a[i]]),i-1]
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=min(t[k*2].val,t[k*2+1].val);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=1e9;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int x,int d)
{
    if(t[k].r<x||t[k].l>x)return;
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
    if(t[k].l>r||t[k].r<l)return 1e9;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    return min(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!b[a[i]])
            b[a[i]]=i;
    }
    build(1,1,n);
    f[1]=1;
    modify(1,1,1);
    for(int i=2;i<=n;i++)
    {
        f[i]=query(1,min(b[a[i]],i-1),i-1)+1;
        modify(1,i,f[i]);
        // cout<<f[i]<<" ";
    }
    cout<<n-f[n]<<endl;
    return 0;
}