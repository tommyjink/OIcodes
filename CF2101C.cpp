#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],tot=0,bb[N],cc[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    set<int> s;
    tot=0;
    for(int i=1;i<=n;i++)s.insert(i),b[i]=bb[i]=0;
    for(int i=1;i<=n;i++)
    {
        auto p=s.upper_bound(a[i]);
        if(p==s.begin())continue;
        b[++tot]=i;
        bb[tot]=bb[tot-1]+i;
        s.erase(--p);
    }
    tot=0,s.clear();
    for(int i=1;i<=n;i++)s.insert(i),c[i]=cc[i]=0;
    for(int i=n;i>=1;i--)
    {
        auto p=s.upper_bound(a[i]);
        if(p==s.begin())continue;
        c[++tot]=i;
        cc[tot]=cc[tot-1]+i;
        s.erase(--p);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(b[i]<=c[i])ans=max(ans,cc[i]-bb[i]);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}