#include<bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e18;
int n,m,h[N],l[N],r[N],tag[N];
vector<int> g[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
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
    int id[4]={x.mx,x.cmx,y.mx,y.cmx};
    sort(id,id+4,cmp);
    return {id[3],id[2]};
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
    return merge(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
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
    // while(1)
    // {
    //     int l,r;cin>>l>>r;
    //     cout<<query(1,l,r).mx<<" "<<query(1,l,r).cmx<<endl;
    // }
    for(int i=1;i<=m;i++)
        q.push({h[query(1,l[i],r[i]).cmx],i});
    for(int i=1;i<=m;i++)
    {
        pii t;
        info res;
        while(1)
        {
            t=q.top();q.pop();
            if(tag[t.second])continue;
            res=query(1,l[t.second],r[t.second]);
            if(h[res.cmx]!=t.first)continue;
            break;
        }
        // cout<<t.first<<","<<t.second<<","<<res.mx<<","<<res.cmx<<endl;
        h[res.mx]=h[res.cmx];
        upd(1,res.mx);
        tag[t.second]=true;
        for(int j:g[res.mx])
            q.push({h[query(1,l[j],r[j]).cmx],j});
    }
    for(int i=1;i<=n;i++)
        cout<<h[i]<<" ";
    cout<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=h[i];
    cout<<ans<<endl;
    return 0;
}