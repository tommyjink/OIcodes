#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=200;
int n,m,a[N][N],f1[N][N],f2[N][N],vis[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='R')
                a[i][j]=1;
            else a[i][j]=2;
        }
    }
    int ans=min(n,m),cnt=5000,now=n*m;
    while(now&&cnt--)
    {
        int mx=0,my=0,mn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                f1[i][j]=min({f1[i-1][j],f1[i][j-1],f1[i-1][j-1]})+1;
                f2[i][j]=min({f2[i-1][j],f2[i][j-1],f2[i-1][j-1]})+1;
                if(a[i][j]==1)f2[i][j]=0;
                if(a[i][j]==2)f1[i][j]=0;
                if(!vis[i][j]&&max(f1[i][j],f2[i][j])>mn)
                {
                    mn=max(f1[i][j],f2[i][j]);
                    mx=i,my=j;
                }
            }
        }
        vis[mx][my]=true;
        ans=min(ans,mn);
        for(int i=mx-mn+1;i<=mx;i++)
            for(int j=my-mn+1;j<=my;j++)
                if(a[i][j])now--,a[i][j]=0;
    }
    cout<<ans<<endl;
    return 0;
}
