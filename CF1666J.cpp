#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205;
int n,c[N][N],dp[N][N],ans[N],sav[N][N];
int cal(int x,int y,int xx,int yy)
{
    if(xx<x||yy<y)return 0;
    return c[xx][yy]-c[x-1][yy]-c[xx][y-1]+c[x-1][y-1];
}
void dfs(int l,int r,int p){
    if(l>r)return;
    ans[sav[l][r]]=p;
    if(l==r)return;
    dfs(l,sav[l][r]-1,sav[l][r]);
    dfs(sav[l][r]+1,r,sav[l][r]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>c[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j]+=c[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j]+=c[i-1][j];
    // return 0;
    for(int i=1;i<=n;i++)sav[i][i]=i;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            dp[i][j]=1e15;
            for(int k=i;k<=j;k++)
            {
                int cost=dp[i][k-1]+dp[k+1][j]+cal(1,i,i-1,k-1)+cal(i,k,k-1,n)+cal(1,k+1,k,j)+cal(k+1,j+1,j,n);
                if(cost<dp[i][j])dp[i][j]=cost,sav[i][j]=k;
            }
            // printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
        }
    }
    dfs(1,n,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}