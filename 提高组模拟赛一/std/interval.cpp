#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,q,tot,head[N],dep[N],fa[N][20];
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
    e[++tot]=(edge){y,head[x]};
    head[x]=tot;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=19;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
    if(x==y)return x;
    for(int i=19;i>=0;i--)
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int dis(int x,int y)
{
    if(!x||!y)return -1;
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void upd(node &a,int &mx,int x,int y)
{
    int d=dis(x,y);
    if(d>mx)mx=d,a=(node){x,y};
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
    if(l==r){t[p]=(node){l,l};return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);build(p<<1|1,mid+1,r);
    t[p]=merge(t[p<<1],t[p<<1|1]);
}
node query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return t[p];
    int mid=(l+r)>>1;node res=(node){0,0};
    if(L<=mid)res=merge(res,query(p<<1,l,mid,L,R));
    if(R>mid)res=merge(res,query(p<<1|1,mid+1,r,L,R));
    return res;
}
signed main()
{
    freopen("interval.in","r",stdin);
    freopen("interval.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1,x,y;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
    queue<int> que;que.push(1);dep[1]=1;
    while(que.size())
    {
        int x=que.front();que.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(y==fa[x][0])continue;
            fa[y][0]=x;dep[y]=dep[x]+1;que.push(y);
        }
    }
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
    build(1,1,n);
    while(q--)
    {
        int l,r;cin>>l>>r;
        node res=query(1,1,n,l,r);
        cout<<dis(res.x,res.y)<<endl;
    }
    return 0;
}
