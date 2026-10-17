#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i],sum+=a[i];
    for(int i=1;i<=n;i++)cin>>b[i],sum-=b[i];
    if(sum!=0)cout<<"-1",exit(0);
    sort(c+1,c+1+n);
    int o=((b[1]-a[1])%n+n)%n;
    for(int i=1;i<=n;i++)
        if(((b[i]-a[i])%n+n)%n!=o)cout<<"-1",exit(0);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,a[i]-b[i]);
    for(int i=1;i<=min(n,ans+1);i++)
        if(c[i]<i-1)cout<<"-1",exit(0);
    cout<<ans<<endl;
    return 0;
}