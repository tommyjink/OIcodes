#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int n,K,w[N],dp[N][N][N][2];
int tot=0,head[N],dep[N];
vector<int> root;
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dfs(int x,int fa,int now)
{
    root.emplace_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dep[v]=dep[x]+e[i].val;
        dfs(v,x,now+1);
        for(auto j:root)
        {
            for(int k=1;k<=K;k++)
            {
                dp[x][j][k][1]=min(dp[x][j][k][1],dp[x][j][k])
            }
        }
    }
    root.pop_back();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>K;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>w[i+1]>>x>>y;
        add(i+1,x+1,y);
        add(x+1,i+1,y);
    }
    n++;

    return 0;
}