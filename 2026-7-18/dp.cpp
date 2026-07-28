#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,INF=1e16;
int n,a[N],b[N],q,L[N],R[N],c[N],lazy[N],ans[N];
pii v[N];
vector<int> qu[N];
struct node
{
    int l,r,mn;
}t[N*8];
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
    // cout<<"!!"<<endl;
    for(int i=1;i<=q;i++)
        qu[R[i]].push_back(i);
    build(1,1,2*n);
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(a+1,a+1+i,b[i])-a;
        // cout<<i<<","<<p<<endl;
        if(p!=i)add(1,p,i,1);
        for(int now:qu[i])
        {
            int l=L[now];
            if(query(1,l,i)!=0)ans[now]=1;
            // cout<<l<<"__"<<i<<"|"<<query(1,l,i)<<endl;
        }
    }
    for(int i=1;i<=q;i++)
        if(ans[i])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    cin>>q;
    for(int i=1;i<=q;i++)cin>>L[i]>>R[i];
    int tag=1;
    for(int i=1;i<n;i++)
        if(a[i]>=a[i+1])tag=0;
    solve1(),exit(0);
    if(tag)solve2();
    else solve1();
    return 0;
}