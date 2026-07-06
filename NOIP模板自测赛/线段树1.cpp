#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
struct node
{
    int l,r,val,lazy;
}t[N*4];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void pushdown(int k)
{
    t[k*2].val+=(t[k*2].r-t[k*2].l+1)*t[k].lazy;
    t[k*2+1].val+=(t[k*2+1].r-t[k*2+1].l+1)*t[k].lazy;
    t[k*2].lazy+=t[k].lazy;
    t[k*2+1].lazy+=t[k].lazy;
    t[k].lazy=0;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val+=(t[k].r-t[k].l+1)*d;
        t[k].lazy+=d;
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query(k*2,l,r)+query(k*2+1,l,r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(m--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int x,y,z;
            cin>>x>>y>>z;
            add(1,x,y,z);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}