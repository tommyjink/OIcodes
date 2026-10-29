#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,m,col[N],vis[N];
int tot,head[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
bool dfs(int x,int now)
{
    // cout<<x<<"!"<<endl;
    vis[x]=true;
    col[x]=now;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to,o=now^e[i].val;
        if(vis[v])
        {
            if(col[v]!=o)return false;
            continue;
        }
        if(!dfs(v,o))return false;
    }
    return true;
}
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(!dfs(i,0))cout<<0<<endl,exit(0);
            cnt++;
        }
    cout<<qpow(2,cnt-1)<<endl;
    
    return 0;
}