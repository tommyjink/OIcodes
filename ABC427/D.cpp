#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,k,dp[2][N][24];
string s;
vector<int> e[N];
void solve()
{
    cin>>n>>m>>k>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        dp[0][i][0]=(s[i]=='A');
        dp[1][i][0]=(s[i]=='B');
        for(int j=1;j<=23;j++)
            dp[0][i][j]=dp[1][i][j]=0;
    }
    for(int i=1;i<=k*2;i++)
    {
        for(int x=1;x<=n;x++)
        {
            for(auto v:e[x])
            {
                if(dp[0][v][i-1]==0)
                    dp[1][x][i]=1;
                if(dp[1][v][i-1]==0)
                    dp[0][x][i]=1;
            }
            // cout<<x<<":"<<dp[0][x][i]<<"!"<<dp[1][x][i]<<endl;
        }
    }
    if(dp[0][1][k*2])cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t;
    cin>>_t;
    while(_t--)
        solve();
    return 0;
}
/*

1
4 6 1
AABB
1 2
2 3
3 1
3 3
3 4
4 2


1
4 6 2
ABAB
1 2
2 3
3 1
3 3
3 4
4 2

*/