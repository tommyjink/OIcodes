#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,f[10];
void solve()
{
    cin>>n;
    int mx=0;
    for(int i=0;i<=9;i++)f[i]=0;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int s=x*y;
        if(s==4)mx=max(mx,z);
        else for(int j=9-s;j>=0;j--)
            f[j+s]=max(f[j+s],f[j]+z);
    }
    int ans=0;
    for(int i=0;i<=9;i++)
        if(i<=5)ans=max(ans,f[i]+mx);
        else ans=max(ans,f[i]);
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