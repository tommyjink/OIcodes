#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=404,M=1<<20;
int n,k;
int tot,head[N];
int dfn[N],b[N],num=0;
int siz[N],dep[N],mx[N];
vector<int> c[N];
bitset<N> f[M];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    dfn[x]=++num;
    b[num]=x;
    siz[num]=1;
    mx[x]=dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        mx[x]=max(mx[x],mx[v]);
    }
    if(mx[x]>=k)c[dep[x]].push_back(dfn[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    if(k*k+1>=n)cout<<"DA",exit(0);
    for(int i=1;i<=k;i++)
    {
        
    }
    return 0;
}