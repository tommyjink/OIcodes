#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,m,vis[N],ans=1;
int head[N],tot=0,in[N],cnt=0;
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
    vis[x]=true,cnt++;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||vis[v])continue;
        dfs(v,x);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        in[x]++,in[y]++;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        if(in[i]!=2)ans=0;
    if(ans&&m==n&&cnt==n)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}