#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,ans=0;
map<vector<int>,int> mp;
signed main()
{
    // freopen("P1360_2.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> v(m,0);
    mp[v]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<m;j++)
            if(x&(1ll<<j))
                v[j]++;
        int mn=1e9;
        for(int j=0;j<m;j++)
            mn=min(mn,v[j]);
        for(int j=0;j<m;j++)
            v[j]-=mn;
        if(mp.count(v))
            ans=max(ans,i-mp[v]);
        else mp[v]=i;
    }
    cout<<ans<<endl;
    return 0;

}