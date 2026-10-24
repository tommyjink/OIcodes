#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,siz[N],f[N],p[N],tag[N],num[N],tot;
vector<int> g[N];
void dfs0(int x,int fa)
{
    siz[x]=(x!=1&&x!=n);
    for(int v:g[x])
    {
        if(v==fa)continue;
        dfs0(v,x);
        siz[x]+=siz[v];
    }
}
void dfs(int x,int fa)
{
    int c=siz[x]-(x!=1&&x!=n),m=c/2;
    for(int i=0;i<=m;i++)
        f[i]=0;
    f[0]=1;
    int k=0;
    for(int v:g[x])
    {
        if(v==fa)continue;
        for(int i=m;i>=siz[v];i--)
            if(!f[i]&&f[i-siz[v]])f[i]=1,p[i]=v,k=max(k,i);
    }
    while(k)
    {
        int v=p[k];
        tag[v]=1,k-=siz[v];
    }
    for(int v:g[x])
    {
        if(v==fa||!tag[v])continue;
        dfs(v,x);
    }
    num[x]=++tot;
    for(int v:g[x])
    {
        if(v==fa||tag[v])continue;
        dfs(v,x);
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
        g[x].push_back(i);
    }
    dfs0(1,0);
    dfs(1,0);
    for(int i=1;i<=n;i++)
        cout<<num[i]<<" ";
    cout<<endl;
    return 0;
}
