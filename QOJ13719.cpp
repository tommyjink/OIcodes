#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=404,M=1<<20;
int n,k;
int tot,head[N];
int dfn[N],b[N],num=0;
int siz[N],dep[N],mx[N];
vector<int> c[N];
vector<pii> d[N];
int f[M];
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
    mx[x]=dep[x]=dep[fa]+1;
    if(dep[x]>k)return;
    dfn[x]=++num;
    b[num]=x;
    siz[num]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        siz[dfn[x]]+=siz[dfn[v]];
        mx[x]=max(mx[x],mx[v]);
    }
    // cout<<x<<"!"<<dep[x]<<","<<dfn[x]<<endl;
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
    dep[0]=-1;
    dfs(1,0);
    if(k*k+1>=n)cout<<"DA",exit(0);
    // for(int i:c[k])cout<<i<<"|";
    // cout<<endl;
    for(int i=1;i<=k;i++)
    {
        for(int j:c[i])
        {
            int l=lower_bound(c[k].begin(),c[k].end(),j)-c[k].begin();
            int r=upper_bound(c[k].begin(),c[k].end(),j+siz[j]-1)-c[k].begin()-1;
            d[l+1].push_back({i,r+1});
            // cout<<j<<":"<<l<<","<<r<<endl;
        }
    }
    int m=c[k].size();
    for(int i=0;i<(1<<k);i++)
    {
        if(f[i]==m)cout<<"DA",exit(0);
        for(auto [dep,r]:d[f[i]+1])
        {
            if(i&(1<<(dep-1)))continue;
            f[i|(1<<(dep-1))]=max(f[i|(1<<(dep-1))],r);
        }
    }
    cout<<"NE"<<endl;
    return 0;
}