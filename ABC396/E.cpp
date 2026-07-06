#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+100;
int n,a[N],b[N],ans=0,anst=0;
struct node
{
    int l,r,maxval,e;
}t[N*8];
struct point
{
    int maxval,e;
};
void push_up(int k)
{
    t[k].maxval=max(t[k*2].maxval,t[k*2+1].maxval);
    if(t[k*2].maxval==t[k].maxval)
        t[k].e+=t[k*2].e;
    if(t[k*2+1].maxval==t[k].maxval)
        t[k].e+=t[k*2+1].e;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
void change(int k,int x,int d,int e)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        if(d>t[k].maxval)
        {  
            t[k].maxval=d;
            t[k].e=e;
        }
        else if(d==t[k].maxval)
        {
            t[k].e+=e;
        }
        return;
    }
    change(k*2,x,d,e);
    change(k*2+1,x,d,e);
    push_up(k);
}
point query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return (point){0,0};
    if(t[k].l>=l&&t[k].r<=r)return (point){t[k].maxval,t[k].e};
    point x=query(k*2,l,r);
    point y=query(k*2+1,l,r);
    int res=max(x.maxval,y.maxval),tot=0;
    if(x.maxval==res)tot+=x.e;
    if(y.maxval==res)tot+=y.e;
    return (point){res,tot};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    build(1,1,n);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+1+n,a[i])-b;
    for(int i=1;i<=n;i++)
    {
        point t=query(1,1,a[i]-1);
        change(1,a[i],t.maxval+1,t.e);
        if(t.maxval>ans)
        {
            ans=t.maxval;
            anst=t.e;
        }
        else if(t.maxval==ans)
        {
            anst+=t.e;
        }
    }
    cout<<ans<<endl<<anst;
    return 0;
}