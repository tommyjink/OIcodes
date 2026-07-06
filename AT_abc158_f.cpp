#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,P=998244353;
int n,x[N],d[N],b[N],f[N],c[N];
pii a[N];
struct node
{
    int l,r,mx=0;
}t[N*4];
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r){t[k].mx=0;return;}
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    t[k].mx=max(t[k*2].mx,t[k*2+1].mx);
}
void modify(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].mx=max(t[k].mx,d);
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    t[k].mx=max(t[k*2].mx,t[k*2+1].mx);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return -1e15;
    if(l<=t[k].l&&t[k].r<=r)return t[k].mx;
    return max(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    build(1,1,n*2);
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>d[i];
        b[i*2-1]=x[i];
        b[i*2]=x[i]+d[i];
    }
    sort(b+1,b+1+2*n);
    int tot=unique(b+1,b+1+2*n)-b-1;
    for(int i=1;i<=n;i++)
    {
        d[i]=lower_bound(b+1,b+1+tot,x[i]+d[i])-b;
        x[i]=lower_bound(b+1,b+1+tot,x[i])-b;
        a[i]=pii(x[i],d[i]);
        // cout<<x[i]<<"!!"<<d[i]<<endl;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)
    {
        x[i]=a[i].first,d[i]=a[i].second;
        // cout<<x[i]<<"!!"<<d[i]<<endl;
        modify(1,x[i],d[i]);
        d[i]=query(1,x[i],max(x[i],d[i]-1));
        modify(1,x[i],d[i]);
        c[x[i]]=i;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<x[i]<<"!"<<d[i]<<endl;
    f[tot+1]=1;
    for(int i=tot;i>=1;i--)
    {
        f[i]=f[i+1]%P;
        if(c[i])f[i]=(f[i]+f[d[c[i]]])%P;
    }
    cout<<f[1];
    return 0;
}