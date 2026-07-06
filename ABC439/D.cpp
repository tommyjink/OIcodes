#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
map<int,int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]]++;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        mp[a[i]]--;
        if(a[i]%5)continue;
        ans+=mp[a[i]/5*7]*mp[a[i]/5*3];
    }
    mp.clear();
    for(int i=1;i<=n;i++)
        mp[a[i]]++;
    for(int i=n;i>=1;i--)
    {
        mp[a[i]]--;
        if(a[i]%5)continue;
        ans+=mp[a[i]/5*7]*mp[a[i]/5*3];
        // cout<<i<<":"<<mp[a[i]/5*7]*mp[a[i]/5*3]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}