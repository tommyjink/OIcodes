#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005;
int n,m,x,y,xx,yy;
int a[N][N];
signed main()
{
    freopen("court.in","r",stdin);
    freopen("court.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>x>>y>>xx>>yy;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)   
            a[i][j]+=a[i-1][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]+=a[i][j-1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}