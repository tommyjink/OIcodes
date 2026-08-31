#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,m,head[N],tag[N];
int mul[N],vis[N];
int a[N],op[N],rt,p[N],v[N];
int b[N],in[N];
vector<int> g[N];
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
void dfs(int x)
{
    mul[x]=1;
    vis[x]=1;
    if(op[x]==2)mul[x]=v[x];
    if(op[x]<=2)return;
    for(int v:g[x])
    {
        if(!vis[v])dfs(v);
        mul[x]=mul[x]*mul[v]%P;
    }
}
void topo()
{
    queue<int> q;
    q.push(rt);
    tag[rt]=1;
    b[rt]=1;
    for(int i=1;i<=rt;i++)
        for(int j:g[i])
            in[j]++;
    while(!q.empty())
    {
        int t=q.front();q.pop();
        int now=b[t];
        for(int v:g[t])
        {
            b[v]=(b[v]+now)%P;
            now=now*mul[v]%P;
            if(!--in[v]&&!tag[v])q.push(v);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>op[i];
        if(op[i]==1)
        {
            cin>>p[i]>>v[i];
        }
        else if(op[i]==2)
        {
            cin>>v[i];
        }
        else
        {
            int k;cin>>k;
            for(int j=1;j<=k;j++)
            {
                int x;cin>>x;
                g[i].push_back(x);
            }
        }
    }
    rt=m+1;
    op[rt]=3;
    int k;cin>>k;
    for(int i=1;i<=k;i++)
    {
        int x;cin>>x;
        g[rt].push_back(x);
    }
    for(int i=1;i<=rt;i++)
    {
        reverse(g[i].begin(),g[i].end());
    }
    dfs(rt);
    topo();
    // for(int i=1;i<=rt;i++)
    //     cout<<mul[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=rt;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
        a[i]=(a[i]*mul[rt])%P;
    for(int i=1;i<=rt;i++)
        if(op[i]==1)a[p[i]]=(a[p[i]]+v[i]*b[i]%P)%P;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}