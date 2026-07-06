#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,M=505,INF=4000000000000000000LL;
int n,a[N],b[N],f[2][M][M];
// bool check(int mid)
// {

// }
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    if(n>=M)
    {
        for(int i=1;i<=n;i++)
            cout<<0<<" ";
        cout<<endl;
        return;
    }
    int now=0;
    for(int j=0;j<=n;j++)
        for(int k=0;k<=n;k++)
            f[now][j][k]=INF;
    for(int j=0;j<=n;j++)
        f[now][j][0]=0;
    for(int i=1;i<=n;i++)
    {
        now^=1;
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                f[now][j][k]=INF;
        f[now][0][0]=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<=n;k++)
            {
                f[now][j][k]=min(f[now^1][j][k],f[now][j-1][k]);
                if(k)f[now][j][k]=min(f[now][j][k],f[now^1][j-1][k-1]+abs(a[i]-b[j]));
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<f[now][n][i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
