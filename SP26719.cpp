#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int dp[100][100];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    dp[1][1]=1;
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
            dp[i][j]+=dp[i-1][j]+dp[i][j-1];
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]<<endl;
    }
    return 0;
}