#include <bits/stdc++.h>
using namespace std;
const int N=755,INF=1e9;
static int a[N][N],p[N][N],dp[N][N];
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("dfs.in","r",stdin);freopen("dfs.out","w",stdout);
    int n;cin>>n;
    for(int j=1;j<n;j++)for(int i=0;i<j;i++){cin>>a[i][j];a[j][i]=a[i][j];}
    for(int i=n-1;i>=0;i--)for(int j=i+1;j<n;j++){
        p[i][j]=p[i+1][j]+p[i][j-1]-p[i+1][j-1]+max(0,-a[i][j]);
        int best=INF;
        for(int k=i;k<j;k++){
            int cut=(i+1<k+1)?p[i+1][j]-p[i+1][k]-p[k+1][j]:0;
            best=min(best,dp[i][k]+dp[k+1][j]+max(0,a[i][k+1])+cut);
        }
        dp[i][j]=best;
    }
    cout<<dp[0][n-1]<<'\n';
}
