#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,siz[N],f[N],p[N],tag[N],num[N];
vector<int> g[N];
void dfs0(int x,int fa)
{
    siz[x]=1;
    for(int v:g[x])
    {
        if(v==fa)continue;
        dfs0(v,x);
        siz[x]+=siz[v];
    }
    // cout<<x<<"="<<siz[x]<<endl;
}
void dfs(int x,int fa,int l,int r)
{
    // cout<<x<<":"<<l<<"~"<<r<<endl;
    int c=siz[x]-1,m=c/2;
    for(int i=0;i<=m;i++)
        f[i]=0;
    f[0]=1;
    int now=0,k=0;
    for(int v:g[x])
    {
        if(v==fa)continue;
        for(int i=m;i>=siz[v];i--)
            if(f[i-siz[v]])f[i]=1,p[i]=v,k=max(k,i);
    }
    now=p[k];
    // cout<<x<<"!"<<k<<","<<p[k]<<","<<m<<","<<c<<endl;
    while(k)
        tag[now]=1,k-=siz[now],now=p[k];
    int ll=l;
    for(int v:g[x])
    {
        if(v==fa||!tag[v])continue;
        dfs(v,x,ll,ll+siz[v]-1);
        ll+=siz[v];
    }
    num[x]=ll++;
    for(int v:g[x])
    {
        if(v==fa||tag[v])continue;
        dfs(v,x,ll,ll+siz[v]-1);
        ll+=siz[v];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        if(i<n)g[x].push_back(i);
    }
    dfs0(1,0);
    dfs(1,0,1,n-1);
    for(int i=1;i<=n-1;i++)
        cout<<num[i]<<" ";
    cout<<n<<endl;
    return 0;
}