#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,lazy[N*4];
struct node
{
    int l,r,val,maxval;
}t[N*4];
vector<pii> a[N];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
    t[k].maxval=max(t[k*2].maxval,t[k*2+1].maxval);
}
void pushdown(int k)
{
    lazy[k*2]+=lazy[k];
    lazy[k*2+1]+=lazy[k];
    t[k*2].val+=lazy[k]*(t[k*2].r-t[k*2].l+1);
    t[k*2+1].val+=lazy[k]*(t[k*2+1].r-t[k*2+1].l+1);
    t[k*2].maxval+=lazy[k];
    t[k*2+1].maxval+=lazy[k];
    lazy[k]=0;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
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
        lazy[k]+=d;
        t[k].val+=d*(t[k].r-t[k].l+1);
        t[k].maxval+=d;
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
int query_sum(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query_sum(k*2,l,r)+query_sum(k*2+1,l,r);
}
int query_max(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return -1e9;
    if(l<=t[k].l&&t[k].r<=r)return t[k].maxval;
    pushdown(k);
    return max(query_max(k*2,l,r),query_max(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[y].push_back(pii(x,z));
    }
    for(int i=1;i<=n;i++)
        sort(a[i].begin(),a[i].end());
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        add(1,i,i,query_max(1,1,i));
        for(auto j:a[i])add(1,j.first,i,j.second);
        // for(int i=1;i<=n;i++)
        //     cout<<query_max(1,i,i)<<" ";
        // cout<<endl;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<query_max(1,i,i)<<" ";
    // cout<<endl;
    cout<<max(0ll,query_max(1,1,n));
    return 0;
}