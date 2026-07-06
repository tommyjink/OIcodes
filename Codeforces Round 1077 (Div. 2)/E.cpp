#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot=0,d[N],siz[N],ans=0;
int top=0,L[N],R[N],son[N],num[N],t[N],P[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs1(int x,int fa)
{
    siz[x]=1;
    L[x]=++top;
    num[top]=x;
    d[x]=d[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs1(v,x);
        ans+=siz[v]*siz[x]*d[x];
        siz[x]+=siz[v];
        if(!son[x]||siz[v]>siz[son[x]])
            son[x]=v;
    }
    R[x]=top;
}
void dfs(int x,int fa,bool keep)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==son[x])continue;
        dfs(v,x,false);
    }
    if(son[x])dfs(son[x],x,true);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==son[x])continue;
        for(int j=L[v];j<=R[v];j++)
            ans+=t[d[num[j]]]*d[x];
        for(int j=L[v];j<=R[v];j++)
            t[d[num[j]]]++;
    }
    t[d[x]]++;
    if(!keep)for(int i=L[x];i<=R[x];i++)t[d[num[i]]]--;
}
void solve()
{
    cin>>n>>m;
    tot=top=ans=0;
    for(int i=0;i<=n+1;i++)
        head[i]=d[i]=siz[i]=L[i]=R[i]=son[i]=num[i]=t[i]=P[i]=0;
    for(int i=1;i<=n-1;i++)
        P[i]=i+1;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        P[x]=max(P[x],y);
    }
    for(int i=1;i<=n-1;i++)
        add(i,P[i]),add(P[i],i);
    // cout<<"!done"<<endl;
    dfs1(n,0);
    dfs(n,0,true);
    sort(d+1,d+1+n);
    ans=-ans;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j<=n&&d[j]==d[i])j++;
        j--;
        ans+=d[i]*(j-i+1)*(n-i);
        i=j;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}