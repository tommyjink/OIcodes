#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N=300,L=1e7;
int n,m,K,a[N],b[N],in[N];
int f[N][N],dp[L];
signed main()
{
    // freopen("P10339_3.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=K;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=1e13;
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        f[x][y]=min(f[x][y],z);
        f[y][x]=min(f[y][x],z);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(f[i][k]+f[k][j]<f[i][j])
                    f[i][j]=f[i][k]+f[k][j];
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=n;j++)
            if(f[b[i]][1]==f[j][1]+f[j][b[i]]&&a[j])
                in[j]|=(1ll<<(i-1));
    }
    memset(dp,127,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<(1ll<<(K));i++)
        for(int j=1;j<=n;j++)
            dp[i|in[j]]=min(dp[i|in[j]],dp[i]+1);
    cout<<dp[(1ll<<K)-1];
    return 0;
}