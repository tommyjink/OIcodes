#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a,b,col[N],cnt=0,num1[N],num2[N],sum=0,ans=0;
int head[N],vis[N],tag[N],tot=0;
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
    if(x==b)
    {
        tag[x]=true;
        return;
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(tag[v])
        {
            tag[x]=tag[v];
            continue;
        }
        if(vis[v])continue;
        vis[v]=true;
        dfs(v,x);
        if(tag[v])
            tag[x]=true;
    }
}
void dfs1(int x,int d,int *num)
{
    col[x]=d;
    num[col[x]]++;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(tag[v]||col[v])continue;
        // cout<<v<<"?";
        dfs1(v,d,num);
    }
}
signed main()
{
    freopen("junction4.in", "r", stdin);
    freopen("junction.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>a>>b;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    vis[a]=true;
    dfs(a,0);
    for(int i=head[a];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!(tag[v]||col[v]))
            dfs1(v,++cnt,num1);
            // cout<<v<<"!"<<endl;
    }
    for(int i=head[b];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!(tag[v]||col[v]))
            dfs1(v,++cnt,num2);
            // cout<<v<<"!"<<endl;
    }
    // for(int i=1;i<=n;i++)   
    //     cout<<col[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=cnt;i++)
        sum+=num1[i];
    for(int i=1;i<=cnt;i++)
    {
        // cout<<num[i]<<endl;
        ans+=num2[i]*sum;
    }
    cout<<ans<<endl;
    return 0;
}