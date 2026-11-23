#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,P=998244353;
int n,deg[N],col[N];
int head[N],tot=1,cnt=0,d[N],f[N];
int siz[N],vis[N],ans=1,dep[N],res=0;
vector<int> V[N],bk;
struct node
{
    int to,next,from,ban;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
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
void dfs(int x,int now)
{
    // cout<<x<<"?"<<endl;
    col[x]=now;
    V[now].push_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(col[v])continue;
        dfs(v,now);
    }
}
void dfs1(int x)
{
    vis[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(e[i].ban)continue;
        if(vis[v]){bk.push_back(i);continue;}
        e[i^1].ban=true;
        dep[v]=dep[x]+1;
        f[v]=x;
        dfs1(v);
    }
}   
void dfs2(int x,int fa)
{
    siz[x]=1;
    // cout<<x<<":"<<endl;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        // cout<<v<<" "<<i<<" "<<bk[0]<<" "<<fa<<endl;
        if(v==fa||bk[0]==i||(bk[0]^1)==i)continue;
        dfs2(v,x);
        siz[x]+=siz[v];
    }
    // cout<<x<<"!"<<siz[x]<<endl;
    res=(res+siz[x]-1+P)%P;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    while(dep[x]>dep[y])x=f[x];
    if(x==y)return x;
    while(x!=y)x=f[x],y=f[y];
    return x;
}
int dis(int x,int y)
{
    int o=lca(x,y);
    return dep[x]+dep[y]-2*dep[o];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        deg[x]++,deg[y]++;
    }
    // for(int i=1;i<=n;i++)
    // cout<<deg[i]<<" ";
    // cout<<endl;
    int c0=0,c1=0,c2=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i])continue;
        dfs(i,++cnt);
        int m=V[cnt].size(),num=0;
        for(int x:V[cnt])num+=deg[x];
        num/=2;
        // cout<<num<<" "<<m<<endl;
        if(num==m)c0++;
        if(num+1==m)c1++;
        if(num==m+1)c2++;
    }
    // cout<<c0<<" "<<c1<<" "<<c2<<endl;
    int fac=qpow(2,cnt-1);
    if(c0==cnt)
    {
        ans=0;
        for(int i=1;i<=cnt;i++)
        {
            bk.clear();
            dfs1(V[i][0]);
            int x=e[bk[0]].from,y=e[bk[0]].to;
            // cout<<x<<","<<y<<endl;
            res=0;
            dfs2(x,0);
            dfs2(y,0);
            ans=(ans+fac*res%P)%P;
        }
        // cout<<"!"<<endl;
    }
    else if(c0==cnt-2&&c1==1&&c2==1)
    {
        ans=1;
        for(int i=1;i<=cnt;i++)
        {
            int m=V[i].size(),num=0;
            for(int x:V[i])num+=deg[x];
            num/=2;
            if(num==m)ans=ans*2%P;
            else if(num+1==m)ans=ans*m%P;
            else if(num==m+1)
            {
                bk.clear();
                dep[V[i][0]]=0;
                f[V[i][0]]=0;
                dfs1(V[i][0]);
                int x=e[bk[0]].from,y=e[bk[0]].to;
                int xx=e[bk[1]].from,yy=e[bk[1]].to;
                int res=(dis(x,xx)+1+dis(y,xx)+1+dis(x,yy)+1+dis(y,yy)+1)%P;
                ans=ans*res%P;
            }
        }
    }
    else ans=0;
    cout<<ans<<endl;
    return 0;
}