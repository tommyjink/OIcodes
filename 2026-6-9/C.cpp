#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e18;
int n,ans[N];
struct event
{
    int l,r,d;
};
vector<event> e[N];
struct node
{
    int mn,add,id,bmn,best,tag;
}tr[N*4];
void pushup(int u)
{
    tr[u].mn=min(tr[u*2].mn,tr[u*2+1].mn);
    tr[u].id=tr[u].bmn=-INF;
    if(tr[u*2].mn==tr[u].mn)
    {
        tr[u].id=max(tr[u].id,tr[u*2].id);
        tr[u].bmn=max(tr[u].bmn,tr[u*2].bmn);
    }
    if(tr[u*2+1].mn==tr[u].mn)
    {
        tr[u].id=max(tr[u].id,tr[u*2+1].id);
        tr[u].bmn=max(tr[u].bmn,tr[u*2+1].bmn);
    }
    tr[u].best=max(tr[u*2].best,tr[u*2+1].best);
}
void build(int u,int l,int r)
{
    tr[u].mn=tr[u].add=0;
    tr[u].bmn=tr[u].best=tr[u].tag=-INF;
    if(l==r)
    {
        tr[u].id=-l;
        return;
    }
    int mid=(l+r)>>1;
    build(u*2,l,mid);
    build(u*2+1,mid+1,r);
    pushup(u);
}
void addtag(int u,int d)
{
    tr[u].mn+=d;
    tr[u].add+=d;
}
void maxtag(int u,int x)
{
    tr[u].bmn=max(tr[u].bmn,x+tr[u].id);
    tr[u].best=max(tr[u].best,tr[u].bmn);
    tr[u].tag=max(tr[u].tag,x);
}
void pushdown(int u)
{
    if(tr[u].add)
    {
        addtag(u*2,tr[u].add);
        addtag(u*2+1,tr[u].add);
        tr[u].add=0;
    }
    if(tr[u].tag!=-INF)
    {
        if(tr[u*2].mn==tr[u].mn)maxtag(u*2,tr[u].tag);
        if(tr[u*2+1].mn==tr[u].mn)maxtag(u*2+1,tr[u].tag);
        tr[u].tag=-INF;
    }
}
void add(int u,int l,int r,int x,int y,int d)
{
    if(x<=l&&r<=y)
    {
        addtag(u,d);
        return;
    }
    pushdown(u);
    int mid=(l+r)>>1;
    if(x<=mid)add(u*2,l,mid,x,y,d);
    if(y>mid)add(u*2+1,mid+1,r,x,y,d);
    pushup(u);
}
int query(int u,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return tr[u].best;
    pushdown(u);
    int mid=(l+r)>>1,res=-INF;
    if(x<=mid)res=max(res,query(u*2,l,mid,x,y));
    if(y>mid)res=max(res,query(u*2+1,mid+1,r,x,y));
    return res;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n+1;i++)e[i].clear();
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l<i&&i<r)
        {
            e[l+1].push_back({i,r-1,1});
            e[i+1].push_back({i,r-1,-1});
        }
    }
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        for(auto j:e[i])
            add(1,1,n,j.l,j.r,j.d);
        maxtag(1,i-1);
        ans[i]=-query(1,1,n,i,n);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
