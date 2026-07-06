#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5,M=64;
int n,m,p[M],d[N],vis[N];
int head[N],tot=0;
struct node
{
    int from,to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
void insert(int x)
{
    for(int i=M-1;i>=0;i--)
        if((x>>i)&1)
        {
            if(!p[i]){p[i]=x;return;}
            else x^=p[i];
        }
}
int query(int x)
{
    int res=x;
    for(int i=M-1;i>=0;i--)
        if((res^p[i])>res)
            res^=p[i];
    return res;
}
void dfs(int x,int res)
{
    vis[x]=true,d[x]=res;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to,val=e[i].val;
        if(!vis[v]) dfs(v,res^val);
        else insert(res^val^d[v]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    cout<<query(d[n]);
    return 0;
}