#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e18;
int n,a[N];
map<pii,int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=-INF,base=0;
    for(int i=1;i<n;i++)
    {
        int w;
        cin>>w;
        if(a[i]==a[i+1])base+=w;
        else 
        {
            int x=min(a[i],a[i+1]);
            int y=max(a[i],a[i+1]);
            if(mp.count({x,y}))mp[{x,y}]+=w;
            else mp[{x,y}]=w;
        }
    }
    ans=max(ans,base);
    for(auto [x,y]:mp)
        ans=max(ans,base+mp[x]);
    cout<<ans<<endl;
    return 0;
}