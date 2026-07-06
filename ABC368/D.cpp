#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,k,val[N],tag[N],cnt[N];
int head[N],tot=0;
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        if(val[v])cnt[x]++;
        val[x]+=val[v];  
    }
    if(cnt[x]>=2)tag[x]=true;
}
void dfs2(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(tag[x]&&val[v])
            tag[v]=true;
        dfs2(v,x);
    }
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
    for(int i=1;i<=k;i++)
    {
        int x;cin>>x;
        val[x]=tag[x]=1;
    }
    dfs(1,0),dfs2(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(tag[i])ans++;
    cout<<ans<<endl;
    return 0;
}