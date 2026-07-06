#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m;
pii a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    for(int i=1;i<=m;i++)
        cin>>b[i].first>>b[i].second;
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
        a[i].second=max(a[i].second,a[i-1].second);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int p=upper_bound(a+1,a+1+n,pii(b[i].first,INF))-a-1;
        // cout<<p<<":"<<a[p].first<<","<<a[p].second<<","<<b[i].first<<","<<b[i].second<<endl;
        if(p>=1&&p<=n)ans=max(ans,ans+a[p].second-b[i].second);
    }
    cout<<ans<<endl;
    return 0;
}