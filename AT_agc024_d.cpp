#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=105;
int tot,head[N],dep[N];
int n,son[N],mx[N];
int s,t,fa[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x)
{
    son[x]=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x])continue;
        dep[v]=dep[x]+1;
        fa[v]=x;
        dfs(v);
        son[x]++;
    }
}
pii solve(int x,int y)
{
    // int d=dep[t]/2,x=t,y;
    // for(int i=1;i<=d;i++)
    //     x=fa[x];
    // y=fa[x];
    for(int i=0;i<=n;i++)
        fa[i]=0,dep[i]=0,mx[i]=0;
    // cout<<x<<"!!"<<y<<endl;
    fa[x]=y;
    fa[y]=x;
    dfs(x);
    dfs(y);
    for(int i=1;i<=n;i++)
    {
        mx[dep[i]]=max(mx[dep[i]],son[i]);
    }
    int ans=2;
    for(int i=0;i<=n;i++)
    {
        if(!mx[i])
        {
            return {i+1,ans};
        }
        ans*=mx[i];
    }
}
pii solve1(int x)
{

    for(int i=0;i<=n;i++)
        fa[i]=0,dep[i]=0,mx[i]=0;
    dfs(x);
    for(int i=1;i<=n;i++)
        mx[dep[i]]=max(mx[dep[i]],son[i]);
    int ans=1;
    for(int i=0;i<=n;i++)
    {
        if(!mx[i])
        {
            return {i+1,ans};
        }
        ans*=mx[i];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        if(!s||dep[i]>dep[s])
            s=i;
    for(int i=1;i<=n;i++)
        fa[i]=0,dep[i]=0;
    dfs(s);
    for(int i=1;i<=n;i++)
        if(!t||dep[i]>dep[t])
            t=i;
    // cout<<s<<"::"<<t<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<dep[i]<<" ";
    // cout<<"!!!!!!"<<endl;
    pii ans;
    if(dep[t]%2==0)
    {
        int d=dep[t]/2,y=t;
        for(int i=1;i<=d;i++)
            y=fa[y];
        // cout<<y<<endl;
        ans=solve1(y);
        // cout<<ans.first<<" "<<ans.second<<endl;
        for(int i=head[y];i;i=e[i].next)
        {
            int v=e[i].to;
            // cout<<y<<","<<v<<":"<<solve(y,v).first<<" "<<solve(y,v).second<<endl;
            ans=min(ans,solve(y,v));
        }
        // cout<<x<<endl;
        // ans=min({solve(x,y),solve(y,z),solve1(y)});
    }
    else
    {
        int d=dep[t]/2,x=t,y=0;
        for(int i=1;i<=d;i++)
            x=fa[x];
        y=fa[x];
        ans=solve(x,y);
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    // cout<<"???"<<endl;
    
    return 0;
}