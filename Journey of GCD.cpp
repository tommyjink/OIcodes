#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=2e6+10,V=1e6+10,M=22;

int n,q,maxa=0,tot,ecnt=0,rt=1;
int a[V],qx[V],qy[V],headv[V],rep[V],nt[V];
int dsu[N],val[N],fa[M][N],dep[N],head[N],to[N],nxt[N],st[N];

inline int find(int x)
{
    if(dsu[x]==x)return x;
    return dsu[x]=find(dsu[x]);
}

inline void add(int x,int y)
{
    ecnt++;
    to[ecnt]=y;
    nxt[ecnt]=head[x];
    head[x]=ecnt;
}
void merge(int x,int y,int w)
{
    x=find(x);
    y=find(y);
    if(x==y)return;
    tot++;
    val[tot]=w;
    fa[0][x]=tot;
    fa[0][y]=tot;
    add(tot,x);
    add(tot,y);
    dsu[x]=dsu[y]=dsu[tot]=tot;
    rt=tot;
}

void build()
{
    tot=n;
    for(int i=1;i<=n;i++)
    {
        dsu[i]=i;
        val[i]=a[i];
        nt[i]=headv[a[i]];
        headv[a[i]]=i;
    }
    for(int i=1;i<=maxa;i++)
        if(headv[i])
        {
            rep[i]=headv[i];
            for(int j=nt[headv[i]];j;j=nt[j])
                merge(headv[i],j,i);
        }
    for(int i=maxa;i>=1;i--)
    {
        int last=0;
        for(int j=i;j<=maxa;j+=i)
            if(rep[j])
            {
                if(last)merge(last,rep[j],i);
                else last=rep[j];
            }
    }
}

void init()
{
    int l=1,r=1;
    st[1]=rt;
    dep[rt]=1;
    while(l<=r)
    {
        int x=st[l++];
        for(int i=head[x];i;i=nxt[i])
        {
            dep[to[i]]=dep[x]+1;
            st[++r]=to[i];
        }
    }
    for(int i=1;i<M;i++)
        for(int j=1;j<=tot;j++)
            fa[i][j]=fa[i-1][fa[i-1][j]];
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=M-1;i>=0;i--)
        if(dep[fa[i][x]]>=dep[y])
            x=fa[i][x];
    if(x==y)return x;
    for(int i=M-1;i>=0;i--)
        if(fa[i][x]!=fa[i][y])
        {
            x=fa[i][x];
            y=fa[i][y];
        }
    return fa[0][x];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    for(int i=1;i<=q;i++)cin>>qx[i]>>qy[i];
    build();
    init();
    for(int i=1;i<=q;i++)
    {
        if(qx[i]==qy[i])cout<<a[qx[i]]<<endl;
        else cout<<val[lca(qx[i],qy[i])]<<endl;
    }
    return 0;
}
