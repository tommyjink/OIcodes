#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,m,k,a[N];
void solve()
{
    int ans=-1e18;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i];
    for(int i=1;i<=n;i++)
    {
        // cout<<"I="<<i<<endl;
        int now=i+k-1,res=0;
        while(now<=i+n-1)
        {
            // cout<<now<<endl;
            res+=a[now];
            now+=m;
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}