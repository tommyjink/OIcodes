#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=8e5+10,INF=1e17;
int n,a[N],b[N],c[N],m=0;
struct node
{
    int l,r,mn,mx,drop;
}t[N*4];
node merge(node a,node b)
{
    return {a.l,b.r,min(a.mn,b.mn),max(a.mx,b.mx),max({a.drop,b.drop,a.mx-b.mn})};
}
void pushup(int k)
{
    t[k]=merge(t[k*2],t[k*2+1]);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].mn=t[k].mx=c[l];
        t[k].drop=0;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
int querymn(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].mn;
    return min(querymn(k*2,l,r),querymn(k*2+1,l,r));
}
node query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return {0,0,INF,0,0};
    if(l<=t[k].l&&t[k].r<=r)return t[k].drop;
    return merge(query(k*2,l,r),query(k*2+1,l,r));
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        c[++m]=c[m]+a[i];
        c[++m]=c[m]-b[i];
    }
    for(int i=1;i<=n;i++)
    {
        c[++m]=c[m]+a[i];
        c[++m]=c[m]-b[i];
    }
    for(int i=1;i<=m;i++)
        cout<<c[i]<<" ";
    cout<<endl;
    m/=2;
    build(1,1,2*m);
    while(1)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(1,l,r)<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        if(i%2==0)continue;
        if(querymn(1,i,i+m-1)-c[i-1]<0)cout<<"-1 ";
        else cout<<query(1,i,i+m-1)<<" ";
    }
    return 0;
}