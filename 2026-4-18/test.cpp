#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
const int P=1e9+7;
int n,q,k,b,a[N],head[N],tot=0;
int ans=0,vis[N],lg[N],f[N][21];
int dfn[N],num=0;
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
    f[x][0]=fa;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs1(v,x);
    }
}
void dfs(int x,int y)
{
    if(x>y)return;
    ans=max(ans,x);
    if(x*2+1<y)return;
    for(int i=1;i<=x;i++)
    {
        if(vis[i])return;
        vis[i]=true;
        dfs(i,y);
    }
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
void init()
{
    lg[0]=lg[1];
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    
}
void solve()
{
    dfs(1,3);
    dfs1(1,0);
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {

        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q>>k>>b;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(q--)
    {
        
    }
    return 0;
}