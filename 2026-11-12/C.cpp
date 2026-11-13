#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=5e5+10,INF=1e18;
int n,m,lazy[N*8],cnt[N*8];
int sum[N],ans[N],vis[N];
struct node1
{
    int l,r,p,q,w;
}q[N];
vector<int> res;
struct info
{
    int d,b,pos;
};
info merge(info x,info y)
{
    if(x.d<y.d)return x;
    if(x.d>y.d)return y;
    if(x.b<y.b)return x;
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
        lazy[k*2]=max(lazy[k*2],lazy[k]);
        lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
        lazy[k]=0;
        cnt[k]=0;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].g.clear();
    t[k].v={0,1,0};
    lazy[k]=cnt[k]=0;
    if(l==r)
    {
        t[k].v.pos=l;
        t[k].v.d=sum[l];
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
    if(t[k].l>r||t[k].r<l)return {INF,INF,0};
    if(l<=t[k].l&&t[k].r<=r)return t[k].v;
    pushdown(k);
    return merge(querymin(k*2,l,r),querymin(k*2+1,l,r));
}
void querycov(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    for(int i:t[k].g)
        if(!vis[i])res.push_back(i),vis[i]=true;
    t[k].g.clear();
    if(t[k].l==t[k].r)return;
    pushdown(k);
    querycov(k*2,x);
    querycov(k*2+1,x);
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].v.d--;
        t[k].v.b=max(t[k].v.b,d);
        cnt[k]++;
        lazy[k]=max(lazy[k],d);
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
void clear(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r){t[k].v={INF,INF,t[k].l};return;}
    pushdown(k);
    clear(k*2,x);
    clear(k*2+1,x);
    pushup(k);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)sum[i]=0;
    for(int i=1;i<=m;i++)vis[i]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].l>>q[i].r>>q[i].p>>q[i].q>>q[i].w;
        if(q[i].l==q[i].p&&q[i].r==q[i].q&&!q[i].w)continue;
        sum[q[i].l]++,sum[q[i].r+1]--;
    }
    for(int i=1;i<=n;i++)
        sum[i]+=sum[i-1];
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        if(q[i].l==q[i].p&&q[i].r==q[i].q&&!q[i].w)continue;
        cov(1,q[i].p,q[i].q,i);
    }
    for(int i=1;i<=n;i++)
    {
        info t=querymin(1,1,n);
        if(!t.pos||t.d!=0){cout<<"-1"<<endl;return;}
        res.clear();
        clear(1,t.pos);
        querycov(1,t.pos);
        ans[t.pos]=t.b;
        for(int i:res)
            modify(1,q[i].l,q[i].r,q[i].w+t.b);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
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