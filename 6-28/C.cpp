#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],c[N];
void solve()
{
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        c[i]=(b[i]-a[i]+m)%m;
    }
    c[n+1]=m;
    c[n+2]=0;
    sort(c+1,c+n+1+1+1);
    for(int i=2;i<=n+2;i++)
        ans=max(ans,c[i]-c[i-1]);
    cout<<m-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}