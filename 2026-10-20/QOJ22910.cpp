#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,m,a[N];
int f(int x,int y)
{
    return (x)*m+y+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int S=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[f(i,j)],S+=a[f(i,j)];
    for(int j=1;j<=m-1;j++)
    {
        int now=0;
        for(int i=1;i<=n;i++)
        {
            now+=a[f(i,j)];
            int cnt=min(a[f(i,j+1)],now);
            now-=cnt;
            S-=cnt;
        }
    }
    cout<<S<<endl;
    return 0;
}