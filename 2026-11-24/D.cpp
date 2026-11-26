#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,mod=998244353;
int fa[N],n,P,c,ans1,ans2,pw[N];
int tot,w[N],siz[N],fac[N],inv[N];
vector<int> g[N];
int getfa(int x){return x==fa[x]?x:(fa[x]=getfa(fa[x]));}
struct node{int x,y,z;}e[N];
bool cmp(node x,node y){return x.z<y.z;}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
int C(int x,int y)
{
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void dfs(int x)
{
    cout<<x<<endl;
    if(x<=n)siz[x]=1;
    else siz[x]=0;
    int sav=0,ok=0;
    for(int v:g[x])
    {
        fa[v]=x;
        int tmp=P;
        dfs(v);
        if(!tmp&&P)ok=1;
        if(!P||tmp)sav=siz[v]*w[x];
        siz[x]+=siz[v];
    }
    ans1+=ok*sav;
    if(siz[x]*2>n&&!P)
    {
        P=x,c=n-siz[x];
        int a=siz[g[x][0]],b=siz[g[x][1]];
        ans1+=(n-2*c-1)*w[P];
        for(int q=0;;q++)
        {
            int x=q+c+1-b,y=q+c+1-a,z=a+b-c-1;
            if(min({x,y,z})<0)continue;
            ans2=(ans2+fac[c+1]*inv[x]%mod*inv[y]%mod*inv[z]%mod*C(c+q,q)%mod*pw[z]%mod)%mod;
        }
        ans2=ans2*fac[c]%mod;
        return;
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
        fa[i]=i;
    tot=n;
    for(int i=1;i<=n-1;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+n,cmp);
    for(int i=1;i<=n-1;i++)
    {
        int x=getfa(e[i].x),y=getfa(e[i].y);
        if(x==y)continue;
        int now=++tot;
        g[now].push_back(x);
        g[now].push_back(y);
        w[now]=e[i].z;
        fa[x]=fa[y]=now;
    }
    P=0;
    fa[tot]=0;
    ans1=ans2=0;
    dfs(tot);
    cout<<ans1<<" "<<ans2<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    pw[0]=inv[0]=fac[0]=1;
    for(int i=1;i<N;i++)
        pw[i]=pw[i-1]*2%mod,
        fac[i]=fac[i-1]*i%mod;
    inv[N-1]=qpow(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}