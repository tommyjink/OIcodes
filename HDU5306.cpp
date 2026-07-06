#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,q,a[N];
struct node
{
    int l,r;
    int mx,cmx,cnt,sum;
}t[N*4];
void pushup(int k)
{
    t[k].mx=max(t[k*2].mx,t[k*2+1].mx);
    t[k].sum=t[k*2].sum+t[k*2+1].sum;
    int cmx=-INF,cnt=0;
    if(t[k].mx==t[k*2].mx)cnt+=t[k*2].cnt;
    else cmx=max(cmx,t[k].mx);
    if(t[k].mx==t[k*2+1].mx)cnt+=t[k*2+1].cnt;
    else cmx=max(cmx,t[k].mx);
    cmx=max({cmx,t[k*2].cmx,t[k*2+1].cmx});
    t[k].cmx=cmx;
    t[k].cnt=cnt;
}
void update(int k,int d)
{
    if(d>=t[k].mx)return;
    t[k].sum-=(t[k].mx-d)*t[k].cnt;
    t[k].mx=d;
}
void pushdown(int k)
{
    update(k*2,t[k].mx);
    update(k*2+1,t[k].mx);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].mx=a[l];
        t[k].cnt=1;
        t[k].cmx=-1;
        t[k].sum=a[l];
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
    if(l<=t[k].l&&t[k].r<=r&&d>t[k].cmx)
    {
        update(k,d);
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
int query_sum(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].sum;
    pushdown(k);
    return query_sum(k*2,l,r)+query_sum(k*2+1,l,r);
}
int query_mx(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return -INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].mx;
    pushdown(k);
    return max(query_mx(k*2,l,r),query_mx(k*2+1,l,r));
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--)
    { 
        int op;
        cin>>op;
        if(op==0)
        {
            int l,r,d;
            cin>>l>>r>>d;
            modify(1,l,r,d);
        }
        else if(op==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<query_sum(1,l,r)<<endl;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query_mx(1,l,r)<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}