#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=8e3+10,INF=1e10;
int n,typ[N],a[N],b[N],c[N],dp[2][N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=dp[1][i]=-INF;
        char op;cin>>op;
        if(op=='B')typ[i]=0;
        else cin>>a[i]>>b[i],typ[i]=1;
        c[i]=c[i-1]+(1-typ[i]);
    }
    int now=0;
    dp[now][0]=0;
    for(int i=1;i<=n;i++)
    {
        now^=1;
        for(int j=0;j<=c[i];j++)
        {
            dp[now][j]=-INF;
            if(typ[i]==0)
            {
                if(j>0)dp[now][j]=max(dp[now][j],dp[now^1][j-1]);
                if(dp[now^1][j]>=1)dp[now][j]=max(dp[now][j],dp[now^1][j]-1);
            }
            else
            {
                dp[now][j]=max(dp[now^1][min(j+a[i],c[i])],dp[now^1][j]+b[i]);
            }
        }
    }
    for(int i=0;i<=c[n];i++)
        if(dp[now][i]>=0){cout<<c[n]*2-i<<endl;return;}
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
/*
2
2
B
C 1 1
6
B
B
C 2 1
C 1 2
B
B
*/