#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505,P=1e9+7;
int n,m,a[N][N],p[N],ok[N][N],mx[N],mn[N],pos[N][N],f[N][N],g[N][N],dp[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        p[a[1][i]]=i;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=p[a[i][j]],pos[i][a[i][j]]=j;
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=m;i++)mx[i]=0,mn[i]=N;
        for(int r=l;r<=n;r++)
        {
            ok[l][r]=1;
            for(int i=1;i<=m;i++)
            {
                mx[i]=max(mx[i],pos[i][r]);
                mn[i]=min(mn[i],pos[i][r]);
                if(mn[i]!=pos[i][l])ok[l][r]=0;
                if(mx[i]-mn[i]!=r-l)ok[l][r]=0;
            }
            // cout<<l<<"~"<<r<<" "<<ok[l][r]<<endl;
        }
    }
    for(int i=1;i<=n;i++)f[i][i]=1,g[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            if(ok[i][j])f[i][j]=g[i+1][j];
            g[i][j]=f[i][j];
            for(int k=i;k<j;k++)
            {
                g[i][j]=(g[i][j]+f[i][k]*g[k+1][j]%P)%P;
            }
            // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
            // printf("g[%lld][%lld]=%lld\n",i,j,g[i][j]);
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}