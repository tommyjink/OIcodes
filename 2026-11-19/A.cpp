#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,inf=1e18;
int n,x,y,a[N],f[N][3];
void solve()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[0][0]=0,f[0][1]=f[0][2]=inf;
    for(int i=1;i<=n;i++){
        f[i][0]=min(f[i-1][0],f[i-1][2])+1;
        f[i][1]=f[i][2]=inf;
        if(a[i]+y>=x){
            f[i][1]=min(f[i-1][0],f[i-1][1]);
            f[i][2]=f[i-1][2];
        }
        if(i>=2&&a[i-1]+a[i]>=x){
            f[i][2]=min({f[i][2],min(f[i-2][0],f[i-2][1])+1,f[i-2][2]+(2*y<x)});
        }
    }
    cout<<n-min(f[n][0],f[n][2])<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
