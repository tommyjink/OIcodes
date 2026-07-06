#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e3+10;
int n,u,mp[N][N],f[N][N];
int cal(int i,int j)
{
    int a=mp[i][j];
    int b=mp[i][n-j+1];
    int c=mp[n-i+1][j];
    int d=mp[n-i+1][n-j+1];
    f[i][j]=min(a+b+c+d,4-a-b-c-d);
    return f[i][j];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>u;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
            if(s[j]=='#')
                mp[i][j+1]=1;
    }
    int res=0;
    for(int i=1;i<=n/2;i++)
        for(int j=1;j<=n/2;j++)
            res+=cal(i,j);
    cout<<res<<endl;
    while(u--)
    {
        int x,y;
        cin>>x>>y;
        mp[x][y]^=1;
        if(x>n/2) x=n-x+1;
        if(y>n/2) y=n-y+1;
        int t=f[x][y];
        res=res-t+cal(x,y);
        cout<<res<<endl;
    }
    return 0;
}