#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e3+10,P=1e9+7;
int n,m,a[N],b[N],f[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0){f[i][j]=1;continue;}
            f[i][j]=(f[i-1][j]+f[i][j-1]-f[i-1][j-1])%P;
            if(a[i]==b[j])f[i][j]=(f[i][j]+f[i-1][j-1])%P;
            // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
        }
    }
    cout<<(f[n][m]%P+P)%P;
    return 0;
}