#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=600,P=1e9+7;
int n,p[N],a[N],pos[N],dp[N][N],g[N][N],c[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        pos[x]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        p[i]=pos[x];
    }
    int now=p[1],cnt=1;
    a[1]=1;
    while(now!=1)a[now]=++cnt,now=p[now];
    if(cnt!=n)cout<<"0"<<endl,exit(0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>c[a[i]][a[j]];
    for(int i=1;i<=n;i++)g[i][i]=1;
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++) dp[i][j]=(dp[i][j]+(dp[i][k]+g[i][k])*(dp[k+1][j]+g[k+1][j]))%P,g[i][j]=(g[i][j]+dp[i][k]*(dp[k][j]+g[k][j]))%P;
            dp[i][j]=dp[i][j]*c[i][j]%P;
        }
    }
    cout<<(dp[1][n]+g[1][n])%P<<endl;
    return 0;
}