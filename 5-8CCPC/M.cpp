#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int n,a[N][N][5],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y][1]=a[x][y][4]=1;
        a[x][y+1][3]=a[x][y+1][4]=1;
        a[x+1][y][1]=a[x+1][y][2]=1;
        a[x+1][y+1][2]=a[x+1][y+1][3]=1;
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            ans+=a[i][j][1]+a[i][j][2]+a[i][j][3]+a[i][j][4];
    cout<<double(ans)*0.25;
    return 0;
}