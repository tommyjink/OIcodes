#include<bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e17;
int n,m,lazy[N*8],cnt[N*8];
int vis[N*8];
struct info
{
    int d,b,pos;
};
info merge(info x,info y)
{
    if(x.b<y.b)return x;
    if(x.b>y.b)return y;
    if(x.d<y.d)return x;
    return y;
}
struct node
{
    int l,r;
    info v;
    vector<int> g;
}t[N*8];
void pushup(int k)
{
    t[k].v=merge(t[k*2].v,t[k*2+1].v);
}
void pushdown(int k)
{
    if(cnt[k])
    {
        cnt[k*2]+=cnt[k];
        cnt[k*2+1]+=cnt[k];
        t[k*2].v.d-=cnt[k];
        t[k*2+1].v.d-=cnt[k];
        t[k*2].v.b=max(t[k*2].v.b,lazy[k]);
        t[k*2+1].v.b=max(t[k*2+1].v.b,lazy[k]);
        lazy[k]=0;
        cnt[k]=0;
    }
}
void build(int k,int l,int r)
{
    t[k].l,t[k].r=r;
    t[k].g.clear();
    t[k].v={0,1,0};
    lazy[k]=cnt[k]=vis[k]=0;
    if(l==r)
    {
        t[k].v.pos=l;
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
        t[k].g.push_back(d);
        return;
    }
    cov(k*2,l,r,d);
    cov(k*2+1,l,r,d);
}
info querymin(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return {INF,INF};
    if(l<=t[k].l&&t[k].r<=r)return t[k].v;
    pushdown(k);
    return merge(query)
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r,p,q,w;
        cin>>l>>r>>p>>q>>w;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cid,T;
    cin>>cid>>T;
    while(T--)solve();
    return 0;
}