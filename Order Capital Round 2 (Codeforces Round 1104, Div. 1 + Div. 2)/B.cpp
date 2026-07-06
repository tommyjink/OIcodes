#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,a[N],b[N];
void solve()
{
    multiset<int> s;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i],s.insert(b[i]);
    for(int i=1;i<=n;i++)
    {
        auto p=s.lower_bound(a[i]);
        if(p==s.end()){cout<<"-1"<<endl;return;}
        a[i]=*p;s.erase(p);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[j]<a[i])ans++;
    cout<<ans<<endl;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
/*
1 7 3 4 2 6 5
1 3 4 2 6 5 7     5
1 2 3 4 6 5 7.    2
1 2 3 4 5 6 7.    1
*/