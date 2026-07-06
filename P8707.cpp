#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,m,a[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    a[1][1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i&1 || j&1)
                a[i][j]+=a[i-1][j]+a[i][j-1];
    cout<<a[n][m];
    return 0;
}