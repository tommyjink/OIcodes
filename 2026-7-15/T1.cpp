#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e3+10;
int n,dp[N][N],dep[N];
vector<int> g[N];
void dfs(int x)
{
    // cout<<x<<"!"<<endl;
    int cnt=0;
    for(auto v:g[x])
    {
        dep[v]=dep[x]+1;
        dfs(v);
        cnt++;
    }
    if(x==n)return;
    if(!cnt)
        for(int i=1;i<dep[x];i++)dp[x][i]=1;
    else
    {
        for(auto v:g[x])
            for(int i=1;i<dep[x];i++)
                dp[v][i]+=dp[v][i-1];
        for(int i=1;i<dep[x];i++)
        {
            dp[x][i]=1;
            for(auto v:g[x])
                dp[x][i]*=(dp[v][i]+dp[v][dep[x]]);
        }
    }
    // cout<<"??"<<endl;
    for(int i=1;i<=dep[x]-1;i++)
        printf("dp[%lld][%lld]=%lld\n",x,i,dp[x][i]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x<y)swap(x,y);
        g[x].push_back(y);
    }
    dep[n]=1;
    dfs(n);
    return 0;
}