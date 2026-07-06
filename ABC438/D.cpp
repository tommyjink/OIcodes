#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],sum=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        cin>>c[i],sum+=c[i];
    int mx=-1e15,now=0,ans=0;
    for(int i=1;i<=n-1;i++)
    {
        sum+=b[i];
        sum-=c[i];
        ans=max(ans,sum+mx);
        now+=a[i]-b[i];
        mx=max(mx,now);
    }
    cout<<ans<<endl;

    return 0;
}