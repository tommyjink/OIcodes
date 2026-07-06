#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int n,a[N][N],b[N][N],c[N][N],d[N][N],e[N][N];
int aa=0,bb=1,cc=2,dd=3;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
            if(s[j-1]=='#')a[i][j]=1;
    }
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
            if(s[j-1]=='#')e[i][j]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            b[i][n-j+1]=a[j][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][n-j+1]=b[j][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][n-j+1]=c[j][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]!=e[i][j])aa++;
            if(b[i][j]!=e[i][j])bb++;
            if(c[i][j]!=e[i][j])cc++;
            if(d[i][j]!=e[i][j])dd++;
        }
    cout<<min({aa,bb,cc,dd});
    return 0;
}