#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],g[N],k[N],x,y;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    cin>>x>>y;
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x&&a[i]+g[i]-1>=x&&b[i]<=y&&b[i]+k[i]-1>=y)
            ans=i;
    }
    cout<<ans<<endl;
    return 0;
}