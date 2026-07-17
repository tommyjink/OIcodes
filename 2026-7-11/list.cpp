#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,a[N],p[N],lazy[N],cnt=0;
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=max(t[k*2].val,t[k*2+1].val);
}
void pushdown(int k)
{
    if(lazy[k])
    {
        lazy[k*2]+=lazy[k];
        lazy[k*2+1]+=lazy[k];
        t[k*2].val+=lazy[k];
        t[k*2+1].val+=lazy[k];
        lazy[k]=0;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=2*l;
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
        t[k].val+=d;
        lazy[k]+=d;
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return -INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return max(query(k*2,l,r),query(k*2+1,l,r));
}
bool ins(int x)
{
    if(x==n+1)return true;
    if(cnt==n)return false;
    if(x<n+1)x=2*n+2-x;
    if(x>n+1)x-=n+1;
    add(1,x,n,-2);
    cnt++;
    // cout<<x<<"!"<<query(1,1,n)/2<<","<<cnt<<endl;
    if(query(1,1,n)/2<=n-cnt)return true;
    add(1,x,n,2);
    cnt--;
    return false;
}
void del(int x)
{
    if(x==n+1)return;
    if(x<n+1)x=2*n+2-x;
    if(x>n+1)x-=n+1;
    add(1,x,n,2),cnt--;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("list.in","r",stdin);
    freopen("list.out","w",stdout);
    cin>>n;
    for(int i=1;i<=2*n+1;i++)
        cin>>a[i],p[a[i]]=i;
    build(1,1,n);
    int r=0,ans=0;
    for(int l=1;l<=2*n+1;l++)
    {
        while(r<2*n+1&&ins(p[r+1]))r++;
        // cout<<l<<","<<r<<endl;
        ans=max(ans,r-l+1);
        if(l<=r)del(p[l]);
    }
    cout<<ans<<endl;
    return 0;
}