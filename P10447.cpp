#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=22,M=(1<<20);
int n,f[N][M];
int dis[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>dis[i][j];
    memset(f,127,sizeof(f));
    f[1][1]=0;
    for(int i=1;i<(1ll<<n);i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!(i&(1ll<<(j-1))))continue;
            for(int k=1;k<=n;k++)
            {
                if(!(i&(1ll<<(k-1))))continue;
                if(j==k)continue;
                f[j][i]=min(f[j][i],f[k][i^(1ll<<(j-1))]+dis[k][j]);
            }
        }
    }
    cout<<f[n][(1ll<<n)-1];
    return 0;
}