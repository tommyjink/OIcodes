#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m;
multiset<int> s;
pii a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].second>>a[i].first;
    for(int i=1;i<=m;i++)cin>>b[i].first>>b[i].second;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int j=m,ans=0;
    for(int i=n;i>=1;i--)
    {
        while(j&&b[j].first>=a[i].first)s.insert(b[j--].second);
        if(s.empty())continue;
        // cout<<i<<endl;
        auto p=s.upper_bound(a[i].second);
        if(p!=s.begin())
        {
            s.erase(prev(p));
            ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}