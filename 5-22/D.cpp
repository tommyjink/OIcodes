#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,a,b,mp[N][N],f[N][N];
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=gcd(i,a)+gcd(j,b);
    memset(f,0x3f,sizeof(f));
    f[1][1]=mp[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=min(f[i][j],min(f[i-1][j]+mp[i][j],f[i][j-1]+mp[i][j]));
    cout<<f[n][n]<<endl;
    return 0;
}