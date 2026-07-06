#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,a[N][N],p=1;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        p=a[max(p,i)][min(p,i)];
    cout<<p;
    return 0;
}