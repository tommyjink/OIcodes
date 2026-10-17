#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],base=0;
int ans=1e18;
vector<pii> v;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],base=max(base,a[i]);
    for(int i=1;i<=n;i++)cin>>b[i],base=max(base,b[i]);
    for(int i=1;i<=n;i++)
        if(b[i]>a[i])v.push_back({a[i],b[i]});
    int now=0,mn=1e18;
    for(auto [x,y]:v)
    {
        ans=min(ans,now+2*base-x);
        mn=min(mn,now-2*x);
        now=2*y+mn;
    }
    ans=min(ans,now+base);
    cout<<ans<<endl;
    return 0;
}
