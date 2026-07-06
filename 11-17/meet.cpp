#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,f[N][30],dep[N];
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
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
}
void init()
{
    dfs(1,0);
    for(int i=1;i<=29;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=29;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=29;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int dis(int x,int y)
{
    int o=lca(x,y);
    return dep[o]-dep[x]+dep[o]-dep[y];
}
signed main()
{
    freopen("meet.in","r",stdin);
    freopen("meet.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    init();
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int o1=lca(x,y);
        int o2=lca(x,z);
        int o3=lca(y,z);
        int res1=dis(x,o1)+dis(y,o1)+dis(z,o1);
        int res2=dis(x,o2)+dis(y,o2)+dis(z,o2);
        int res3=dis(x,o3)+dis(y,o3)+dis(z,o3);
        int mx=max({res1,res2,res3});
        if(res1==mx)
            cout<<o1<<endl;
        else if(res2==mx)cout<<o2<<endl;
        else cout<<o3<<endl;
    }
    return 0;
}
/*
【样例输入】
6 4
1 2
2 3
2 4
4 5
5 6
4 5 6
6 3 1
2 4 4
6 6 6
【样例输出】
5
2
4
6

*/