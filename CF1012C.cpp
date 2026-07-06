#include <bits/stdc++.h>
#include <iostream>
#define endl "\n"
using namespace std;
const int N = 5e3 + 10;
int n, a[N], f[N][N][3], ans[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int m = (n + 1) / 2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 63, sizeof(f));
    f[0][0][0]=0;
    f[0][0][1]=0;
    for (int i = 1; i <= n; i++)
    {
        f[i][0][0]=f[i][0][1]=0;
        for (int j = 1; j <= m; j++)
        {
            f[i][j][0]=min({f[i-1][j][1],f[i-1][j][0],f[i-1][j][2]+max(a[i]-a[i-1]+1,0)});
            f[i][j][1]=f[i-1][j][2]+max(0,a[i]-a[i-1]+1);
            f[i][j][2]=f[i-1][j-1][0]+max(0,a[i-1]-a[i]+1);
            if(i>1&&j>1)f[i][j][2]=min(f[i][j][2],f[i-1][j-1][1]-max(0,a[i-1]-a[i-2]+1)+max(0,a[i-1]-min(a[i-2],a[i])+1));
            // printf("f[%lld][%lld][0]=%lld\n",i,j,f[i][j][0]);
            // printf("f[%lld][%lld][1]=%lld\n",i,j,f[i][j][1]);
            // printf("f[%lld][%lld][2]=%lld\n",i,j,f[i][j][2]);
        }
    }
    for(int i=1;i<=m;i++)
        cout<<min({f[n][i][0],f[n][i][1],f[n][i][2]})<<" ";
    return 0;
}