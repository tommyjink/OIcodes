#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=35,P=1e9+9,M=1005;
int n,m,c;
int a[N],C[M][M],g[N][N][M],f[N][N][N];
void init()
{
    for(int i = 0; i <= M - 1; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) 
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>c;
    for(int i=1;i<=c;i++)
        cin>>a[i];
    init();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=i*j;k++)
            {
                g[i][j][k]=C[i*j][k];
                // printf("g[%lld][%lld][%lld]=%lld\n",i,j,k,g[i][j][k]);
                for(int l=1;l<=i;l++)
                    for(int r=1;r<=j;r++)
                        if(l*r>=k&&(l!=i||r!=j))
                            g[i][j][k]=((g[i][j][k]-C[i][l]%P*C[j][r]%P*g[l][r][k])%P+P)%P;
                // printf("g[%lld][%lld][%lld]=%lld\n",i,j,k,g[i][j][k]);
            }
    f[0][0][0]=1;
    for(int k=1;k<=c;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int l=0;l<=i-1;l++)
                    for(int r=0;r<=j-1;r++)
                        if((i-l)*(j-r)>=a[k])
                            f[i][j][k]=((f[i][j][k]+f[l][r][k-1]*g[i-l][j-r][a[k]]%P*C[n-l][i-l]%P*C[m-r][j-r]%P)%P+P)%P;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)   
            ans=((ans+f[i][j][c])%P+P)%P;
    cout<<ans<<endl;
    return 0;
}