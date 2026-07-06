#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,head[N],tot=0,op[N];
int f[N],in[N];
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
    if(!in[x])f[x]=1;
    else if(op[x]) f[x]=1e9;
    else f[x]=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        if(op[x])f[x]=min(f[x],f[v]);
        else f[x]+=f[v];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>op[i];
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        add(i,x);
        add(x,i);
        in[x]++;
    }
    dfs(1,0);
    int cnt=0;
    for(int i=1;i<=n;i++)   
        if(!in[i])cnt++;
    cnt=cnt-f[1]+1;
    cout<<cnt<<endl;
    return 0;
}