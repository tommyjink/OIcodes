#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
const int P=998244353;
int n,m,q,T,dep[N];
int tot,head[N],f[N];
int a[N],b[N],suma[N],sumb[N];
int ga[N],gb[N],l[N];
int cnt=0,c[N],l1[N],l2[N];
int X,Y;
struct node
{
    int to,next;
}e[N*2];
struct xyz
{
    int x,y,z;
}r[N];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs1(int x,int fa)
{
    f[x]=fa;
    dep[x]=dep[fa]+1;
    ga[1]+=(dep[x]-1)*a[x];
    gb[1]+=(dep[x]-1)*b[x];
    suma[x]=a[x];
    sumb[x]=b[x];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs1(v,x);
        suma[x]+=suma[v];
        sumb[x]+=sumb[v];
    }
}
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        ga[v]=ga[x]+(suma[1]-suma[v])-suma[v];
        gb[v]=gb[x]+(sumb[1]-sumb[v])-sumb[v];
        dfs(v,x);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    while(dep[x]>dep[y])x=f[x];
    while(x!=y)x=f[x],y=f[y];
    return x;
}
void prep()
{
    dfs1(1,0);
    dfs(1,0);
    X=Y=0;
    for(int i=1;i<=n;i++)
    {
        if(!X||ga[i]<ga[X])X=i;
        if(!Y||gb[i]<gb[Y])Y=i;
    }
    int o=lca(X,Y);
    int x=X,y=Y;
    cnt=0;
    int cnt1=0,cnt2=0;
    while(x!=o)
    {
        l1[++cnt1]=x;
        x=f[x];
    }
    while(y!=o)
    {
        l2[++cnt2]=y;
        y=f[y];
    }
    for(int i=1;i<=cnt1;i++)
        l[++cnt]=l1[i];
    l[++cnt]=o;
    for(int i=cnt2;i>=1;i--)
        l[++cnt]=l2[i];
    for(int i=1;i<=cnt-1;i++)
        c[i]=ga[l[i+1]]-ga[l[i]];
    for(int i=1;i<=cnt-1;i++)
        c[i]=
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q>>T;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>r[i].x>>r[i].y>>r[i].z;
        if(r[i].x==1) a[r[i].y]+=r[i].z;
        else b[r[i].y]+=r[i].z;
    }
    prep();
    // for(int i=1;i<=n;i++)
    //     cout<<ga[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<gb[i]<<" ";
    // cout<<endl;
    // cout<<X<<" "<<Y<<endl;
    while(q--)
    {
        int k;cin>>k;
        for(int i=1;i<=k;i++)
        {
            int x,c,p,w;
            cin>>x>>c>>p>>w;
            if(r[x].x==1)a[r[x].y]-=r[x].z;
            else b[r[x].y]-=r[x].z;
            r[x]={c,p,w};
            if(r[x].x==1)a[r[x].y]+=r[x].z;
            else b[r[x].y]+=r[x].z;
        }
        prep();
    }
    return 0;
}