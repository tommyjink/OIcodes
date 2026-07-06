#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,m,head[N],tot=0;
int a[N],b[N],vis[N],num=0,tag=0,cnt=0;
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
    vis[x]=true;
    cnt++;
    for(int i=head[x];i;i=e[i].next)
    {
        num++;
        int v=e[i].to;
        if(v==x)tag=true;
        if(!vis[v])dfs(v);
    }
}
void solve()
{
    cin>>n;
    tot=0;
    int ans=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)head[i]=vis[i]=0;
    for(int i=1;i<=n;i++)add(a[i],b[i]),add(b[i],a[i]);
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        cnt=num=tag=0,dfs(i);
        if(cnt*2!=num)ans=0;
        else if(tag)ans=ans*n%P;
        else ans=ans*2%P;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}