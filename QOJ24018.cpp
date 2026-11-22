#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
const int P=998244353;
int n,ma,mb,q,v,T,dep[N];
int tot,head[N],f[N];
int a[N],b[N],suma[N],sumb[N];
int ga[N],gb[N],l[N],inv2=0;
int cnt=0,c[N],l1[N],l2[N],d[N];
int X,Y,B=0;
struct node
{
    int to,next;
}e[N*2];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
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
    ga[1]=gb[1]=0;
    dfs1(1,0);
    dfs(1,0);
    X=Y=0;
    for(int i=1;i<=n;i++)
    {
        if(!X||ga[i]<ga[X])X=i;
        if(!Y||gb[i]<gb[Y])Y=i;
    }
    B=ga[X]+gb[Y];
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
        c[i]=min(c[i],gb[l[i]]-gb[l[i+1]]);
    cnt--;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        head[i]=f[i]=dep[i]=a[i]=b[i]=suma[i]=sumb[i]=ga[i]=gb[i]=l[i]=c[i]=l1[i]=l2[i]=d[i]=0;
    tot=0;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    cin>>ma;
    for(int i=1;i<=ma;i++)
    {
        int x,y;
        cin>>x>>y;
        a[y]+=x;
    }
    cin>>mb;
    for(int i=1;i<=mb;i++)
    {
        int x,y;
        cin>>x>>y;
        b[y]+=x;
    }
    cin>>v>>T;
    prep();
    // cout<<cnt<<":"<<endl;
    // for(int i=1;i<=cnt;i++)
    //     cout<<c[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=cnt+1;i++)
    //     cout<<l[i]<<" ";
    // cout<<endl;
    int k1=cnt,k2=cnt;
    for(int i=1;i<=cnt;i++)
        d[i]=c[cnt-i+1];
    for(int i=1;i<cnt;i++)
    {
        if(c[i]>c[i+1])k1=min(k1,i);
        if(d[i]>d[i+1])k2=min(k2,i);
    }
    // cout<<k1<<"!"<<k2<<endl;
    for(int i=1;i<=T;i++)
    {
        int p1=upper_bound(c+1,c+1+k1,i*v)-c-1;
        int p2=upper_bound(d+1,d+1+k2,i*v)-d-1;
        // cout<<p1<<","<<p2<<endl;
        if(p1+p2>cnt)cout<<0<<endl;
        else cout<<cnt-(p1+p2)<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}