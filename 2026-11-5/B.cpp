#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e18;
int n,m,h[N],l[N],r[N];
vector<int> g[N];
struct info{int mx,cmx;};
struct node
{
    int l,r;
    info c;
}t[N*4];
bool cmp(int x,int y)
{
    return h[x]<h[y];
}
inline info merge(info x,info y)
{
    int id[4]={x.mx,x.mx,y.cmx,y.cmx};
    sort(id,id+4);
    return {id[0],id[1]};
}
inline void pushup(int k)
{
    t[k].c=merge(t[k*2].c,t[k*2+1].c);
    return;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].c={l,0};
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void upd(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)return;
    upd(k*2,x),upd(k*2+1,x);
    pushup(k);
}
info query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return {0,0};
    if(l<=t[k].l&&t[k].r<=r)return t[k].c;
    info x={0,0},y={0,0};
    return merge(query(k*2,l,r),query(k*2+1,l,r));
}
int get()
{
    int now=INF,res=0;
    for(int i=1;i<=m;i++)
    {
        if(query())
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    h[0]=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        for(int j=l[i];j<=r[i];j++)
            g[j].push_back(i);
    }
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        info res=query(1,l[i],r[i]);
        h[res.mx]=h[res.cmx];
        upd(1,res.mx);
    }
    return 0;
}