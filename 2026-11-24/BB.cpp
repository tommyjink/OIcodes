#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2505,INF=1e16;
int n,dp[N][N][2];
int tot,depy[N],depx[N];
string s,z;
vector<int> g[N],f[N],V[N];
void dfs(int x,int fa,int rt)
{
    for(int v:g[x])
    {
        if(v==fa)continue;
        dfs(v,x,rt);
    }
    for(int y:V[depx[x]])
    {
        dp[x][y][0]=dp[x][y][1]=INF;
        if(g[x].size()!=f[y].size())continue;
        int A=0,B=0;
        for(int i=0;i<g[x].size();i++)
        {
            int u=g[x][i],v=f[y][i];
            A+=dp[u][v][0];
            v=f[y][f[y].size()-i-1];
            B+=dp[u][v][1];
        }
        if(x==rt)dp[x][y][0]=A;
        else
        {
            dp[x][y][0]=min(A,B+1);
            dp[x][y][1]=min(A+1,B);
        }
    }
}
void solve()
{
    cin>>n>>s>>z;
    for(int i=0;i<=n;i++)
        g[i].clear(),f[i].clear(),V[i].clear();
    s=" "+s;
    z=" "+z;
    n*=2;
    stack<int> stk;
    stk.push(1);
    tot=1;
    depx[1]=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
        {
            depx[++tot]=depx[stk.top()]+1;
            g[stk.top()].push_back(tot);
            stk.push(tot);
        }
        else stk.pop();
    }
    tot=1;
    depy[1]=0;
    V[0].push_back(1);
    for(int i=1;i<=n;i++)
    {
        if(z[i]=='(')
        {
            depy[++tot]=depy[stk.top()]+1;
            V[depy[tot]].push_back(tot);
            f[stk.top()].push_back(tot);
            stk.push(tot);
        }
        else stk.pop();
    }
    dfs(1,0,1);
    if(dp[1][1][0]>=INF)cout<<-1<<endl;
    else cout<<dp[1][1][0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}