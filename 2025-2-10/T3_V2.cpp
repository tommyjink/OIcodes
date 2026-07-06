#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],dp[N][35][35];
//dp[i][x][y] 乘x次 除y次
int cal(int k,int x,int y){return (k>>y)<<x;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(dp,127,sizeof(dp));
    for(int x=0;x<=30;x++)
        for(int y=0;y<=30;y++)
            dp[0][x][y]=0;
    for(int i=1;i<=n;i++)
    {
        for(int x=0;x<=20;x++)
        {
            for(int y=0;y<=20;y++)
            {
                for(int xx=0;xx<=20;xx++)
                {
                    for(int yy=0;yy<=20;yy++)
                    {
                        if(cal(a[i],x,y)>=cal(a[i-1],xx,yy))
                        {
                            dp[i][x][y]=min(dp[i][x][y],dp[i-1][xx][yy]+x+y);
                        }
                    }
                }
            }
        }
    }
    int ans=1e9;
    for(int x=0;x<=30;x++)
        for(int y=0;y<=30;y++)
            ans=min(ans,dp[n][x][y]);
    cout<<ans<<endl;
    return 0;
}