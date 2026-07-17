#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1500,INF=1e15;
int n,a[N],dp[N][N][2],siz[N];
void dfs(int x)
{
    siz[x]=1;
    if(x*2<=n)dfs(x*2),siz[x]+=siz[x*2];
    if(x*2+1<=n)dfs(x*2+1),siz[x]+=siz[x*2+1];
    if(siz[x]==1)dp[x][1][1]=dp[x][0][0]=0;
    for(int cnt=siz[x];cnt>=0;cnt--)
    {
        for(int j=cnt;j>=0;j--)
        {
            for(int s1=0;s1<=1;s1++)for(int s2=0;s2<=1;s2++)
                if(cnt-1-j>=0&&cnt-1-j<=siz[x*2]&&j<=siz[x*2+1])    
                    dp[x][cnt][1]=max(dp[x][cnt][1],dp[x*2][cnt-1-j][s1]+s1*a[x*2]+dp[x*2+1][j][s2]+s2*a[x*2+1]);
            for(int s1=0;s1<=1;s1++)for(int s2=0;s2<=1;s2++)
                if(cnt-j<=siz[x*2]&&j<=siz[x*2+1])
                    dp[x][cnt][0]=max(dp[x][cnt][0],dp[x*2][cnt-j][s1]+(1-s1)*a[x*2]+dp[x*2+1][j][s2]+(1-s2)*a[x*2+1]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<N;j++)
            dp[i][j][0]=dp[i][j][1]=-INF;
    dfs(1);
    cout<<dp[1][n/2][0]<<endl;
    return 0;
}