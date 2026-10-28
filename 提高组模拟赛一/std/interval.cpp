#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,q,tot,cnt,head[N],dep[N],pos[N],lg[N*2];
signed f[N*2][20];
struct edge
{
    int to,next;
}e[N*2];
struct node
{
    int x,y;
}t[N*4];
void add(int x,int y)
{
    e[++tot]={y,head[x]};
    head[x]=tot;
}
int calc(int x,int y)
{
    return dep[x]<dep[y]?x:y;
}
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    pos[x]=++cnt;
    f[cnt][0]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int y=e[i].to;
        if(y==fa)continue;
        dfs(y,x);
        f[++cnt][0]=x;
    }
}
int lca(int x,int y)
{
    int l=pos[x],r=pos[y];
    if(l>r)swap(l,r);
    int k=lg[r-l+1];
    return calc(f[l][k],f[r-(1<<k)+1][k]);
}
int dis(int x,int y)
{
    if(!x||!y)return -1;
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void upd(node &a,int &mx,int x,int y)
{
    int d=dis(x,y);
    if(d>mx)mx=d,a={x,y};
}
node merge(node a,node b)
{
    if(!a.x)return b;
    if(!b.x)return a;
    int x=a.x,y=a.y,mx=dis(x,y);
    upd(a,mx,b.x,b.y);upd(a,mx,x,b.x);upd(a,mx,x,b.y);
    upd(a,mx,y,b.x);upd(a,mx,y,b.y);
    return a;
}
void build(int p,int l,int r)
{
    if(l==r){t[p]={l,l};return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);build(p<<1|1,mid+1,r);
    t[p]=merge(t[p<<1],t[p<<1|1]);
}
node query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return t[p];
    int mid=(l+r)>>1;
    node res={0,0};
    if(L<=mid)res=merge(res,query(p<<1,l,mid,L,R));
    if(R>mid)res=merge(res,query(p<<1|1,mid+1,r,L,R));
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1,x,y;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
    dfs(1,0);
    for(int i=2;i<=cnt;i++)lg[i]=lg[i/2]+1;
    for(int j=1;(1<<j)<=cnt;j++)
        for(int i=1;i+(1<<j)-1<=cnt;i++)
            f[i][j]=calc(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    build(1,1,n);
    while(q--)
    {
        int l,r;cin>>l>>r;
        node res=query(1,1,n,l,r);
        cout<<dis(res.x,res.y)<<endl;
    }
    return 0;
}