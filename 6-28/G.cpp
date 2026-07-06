#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int res=0;
        a[0]=a[n+1]=(1ll<<m)-1;
        for(int j=1;j<=60;j++)
        {
            int x=0,y=0,z=0;
            if(a[i]&(1ll<<(j-1)))x=1;
            if(a[i-1]&(1ll<<(j-1)))y=1;
            if(a[i+1]&(1ll<<(j-1)))z=1;
            if(j<=m&&y&&z)res++;
            else if(j>m&&x)
            {
                res=0;
                break;
            }
        }
        // cout<<res<<"!"<<endl;
        ans+=(1ll<<res)-1;
    }
    cout<<ans<<endl;
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