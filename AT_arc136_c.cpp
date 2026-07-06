#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],sum=0,mx=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
        sum+=abs(a[i]-a[i%n+1]);
    cout<<max(mx,sum/2);
    return 0;
}