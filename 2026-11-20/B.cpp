#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=8e5+10,INF=1e18;
int n;
int a[N],b[N],lst[N];
int c[N],m=0,d[N];
int lazy[N];
struct node
{
    int l,r;
    int mx,val,mn;
}t[N*8];
void pushup(int k)
{
    t[k].mx=max(t[k*2].mx,t[k*2+1].mx);
    t[k].mn=min(t[k*2].mn,t[k*2+1].mn);
    t[k].val=max(t[k*2].val,t[k*2+1].val);
}
void pushdown(int k)
{
    if(~lazy[k])
    {
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        t[k*2].val=max(t[k*2].val,t[k*2].mx-lazy[k]);
        t[k*2+1].val=max(t[k*2+1].val,t[k*2+1].mx-lazy[k]);
        lazy[k]=-1;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=-1;
    if(l==r)
    {
        t[k].mx=c[l];
        t[k].mn=c[l];
        t[k].val=c[l]-d[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void cov(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]=d;
        t[k].val=max(t[k].val,t[k].mx-d);
        return;
    }
    pushdown(k);
    cov(k*2,l,r,d);
    cov(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return max(query(k*2,l,r),query(k*2+1,l,r));
}
int querymn(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].mn;
    pushdown(k);
    return min(querymn(k*2,l,r),querymn(k*2+1,l,r));
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
    for(int i=m+1;i<=2*m;i++)
        c[i]=c[i-m];
    // for(int i=1;i<=2*m;i++)
    //     cout<<c[i]<<" ";
    // cout<<endl;
    d[m]=c[m];
    for(int i=m-1;i>=1;i--) 
        d[i]=min(d[i+1],c[i]);
    build(1,1,2*m);
    stack<int> s;
    for(int i=1;i<=2*m;i++)
    {
        while(!s.empty()&&c[s.top()]>c[i])s.pop();
        if(!s.empty())lst[i]=s.top();
        s.push(i);
    }
    for(int i=m;i<=2*m-2;i++)
    {
        if(i>m)cov(1,lst[i]+1,i,c[i]);
        if((i-m)&1)continue;
        // cout<<querymn(1,i-m+1,i)<<"!";
        if(querymn(1,i-m+1,i)-c[i-m]<0)cout<<"-1"<<" ";
        else cout<<query(1,i-m+1,i)<<" ";
        // for(int i=1;i<=2*m;i++)
        //     cout<<query(1,i,i)<<" ";
        // cout<<endl;
        // cout<<query(1,i-m+1,i)<<" ";
    }
    return 0;
}