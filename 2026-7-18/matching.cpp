#include<bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,INF=1e16;
int n,a[N],b[N],q,L[N],R[N],c[N],lazy[N],ans[N],d[N],e[N];
pii v[N];
vector<int> qu[N];
struct node
{
    int l,r,mn;
}t[N*8];
int mx[N*4];
void pushup(int k)
{
    t[k].mn=min(t[k*2].mn,t[k*2+1].mn);
}
void pushdown(int k)
{
    if(lazy[k])
    {
        t[k*2].mn+=lazy[k];
        lazy[k*2]+=lazy[k];
        t[k*2+1].mn+=lazy[k];
        lazy[k*2+1]+=lazy[k];
        lazy[k]=0;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=0;
    t[k].mn=0;
    if(l==r)return;
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
        t[k].mn+=d;
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
    if(t[k].l>r||t[k].r<l)return INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].mn;
    pushdown(k);
    return min(query(k*2,l,r),query(k*2+1,l,r));
}
void buildmn(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].mn=d[l];
        return;
    }
    int mid=(l+r)>>1;
    buildmn(k*2,l,mid);
    buildmn(k*2+1,mid+1,r);
    pushup(k);
}
int findpos(int k,int l,int r,int L,int v)
{
    if(r<L||t[k].mn>v)return INF;
    if(l==r)return l;
    int mid=(l+r)>>1,res=findpos(k*2,l,mid,L,v);
    if(res!=INF)return res;
    return findpos(k*2+1,mid+1,r,L,v);
}
void buildmx(int k,int l,int r)
{
    if(l==r)
    {
        mx[k]=e[l];
        return;
    }
    int mid=(l+r)>>1;
    buildmx(k*2,l,mid);
    buildmx(k*2+1,mid+1,r);
    mx[k]=max(mx[k*2],mx[k*2+1]);
}
int querymx(int k,int l,int r,int L,int R)
{
    if(l>R||r<L)return 0;
    if(L<=l&&r<=R)return mx[k];
    int mid=(l+r)>>1;
    return max(querymx(k*2,l,mid,L,R),querymx(k*2+1,mid+1,r,L,R));
}
void solve1()
{
    for(int now=1;now<=q;now++)
    {
        int l=L[now],r=R[now],cnt=0;
        // cout<<l<<","<<r<<":"<<endl;
        for(int i=l;i<=r;i++)
            v[++cnt]={a[i],b[i]};
        sort(v+1,v+1+cnt);
        for(int i=0;i<=cnt;i++)c[i]=0;
        for(int i=1;i<=cnt;i++)
        {
            int p=lower_bound(v+1,v+1+i,pii(v[i].second,-INF))-v;
            // cout<<v[i].first<<" "<<v[i].second<<"|"<<p<<endl;
            if(p!=i)c[p]++,c[i+1]--;
        }
        for(int i=1;i<=cnt;i++)c[i]+=c[i-1];
        int tag=1;
        for(int i=1;i<=cnt;i++)
            if(!c[i])tag=0;
        if(tag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
void solve2()
{
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(a+1,a+1+i,b[i])-a;
        if(p<i)d[i]=p;
        else d[i]=INF;
    }
    buildmn(1,1,n);
    for(int i=1;i<=n;i++)
        e[i]=findpos(1,1,n,i,i);
    buildmx(1,1,n);
    for(int i=1;i<=q;i++)
    {
        int l=L[i],r=R[i];
        if(findpos(1,1,n,l+1,l)>r)cout<<"No"<<endl;
        else if(querymx(1,1,n,l+1,r)>r)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("matching.in","r",stdin);
    // freopen("matching.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    cin>>q;
    for(int i=1;i<=q;i++)cin>>L[i]>>R[i];
    int tag=1;
    int sum=0;
    for(int i=1;i<n;i++)
        if(a[i]>=a[i+1])tag=0;
    for(int i=1;i<=q;i++)
        sum+=R[i]-L[i]+1;
    solve2();
    // else solve1();
    return 0;
}
