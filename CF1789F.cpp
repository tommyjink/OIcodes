#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=85;
int n,s[N],dp[N][N],dp1[N][N][N],v[N],cnt=0;
int cal2(int x)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<x;i++)
    {
        for(int j=x;j<=n;j++)
        {
            if(s[i]==s[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=dp[i-1][j-1];
            dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
    }
    return dp[x-1][n];
}
int cal3(int x,int y)
{
    memset(dp1,0,sizeof(dp1));
    for(int i=1;i<x;i++)
    {
        for(int j=x;j<y;j++)
        {
            for(int k=y;k<=n;k++)
            {
                if(s[i]==s[j]&&s[j]==s[k])
                    dp1[i][j][k]=dp1[i-1][j-1][k-1]+1;
                else dp1[i][j][k]=dp1[i-1][j-1][k-1];
                dp1[i][j][k]=max({dp1[i][j][k],dp1[i-1][j][k],dp1[i][j-1][k],dp1[i][j][k-1]});
            }
        }
    }
    return dp1[x-1][y-1][n];
}
int cal5()
{
    int now=1,res=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==v[now])
            now++;
        if(now==cnt+1)
            res++,now=1;
    }
    if(res>=2)return res;
    else return 0;
}
int solve2()
{
    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,cal2(i));
    return res*2;
}
int solve3()
{
    int res=0;
    for(int i=1;i<=n;i++)   
        for(int j=i;j<=n;j++)
            res=max(res,cal3(i,j));
    return res*3;
}
int solve5()
{
    int m=n/5,res=0;
    if(m==0)return 0;
    for(int k=1;k+m-1<=n;k++)
    {
        // cout<<k<<endl;
        for(int i=1;i<(1ll<<min(m,n-k+1));i++)
        {
            cnt=0;
            for(int j=1;j<=m;j++)
                if(i&1ll<<(j-1))
                    v[++cnt]=s[k+j-1];
            res=max(res,cal5()*cnt);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    cin>>t;
    n=t.length();
    // cout<<n<<endl;
    for(int i=1;i<=n;i++)
        s[i]=t[i-1]-'a'+1;
    cout<<max({solve2(),solve3(),solve5()});
    return 0;
}