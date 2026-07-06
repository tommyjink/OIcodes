#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n;
pii a[N];
set<int> s;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].second;
    for(int i=1;i<=n;i++)
        cin>>a[i].first;
    s.clear();
    for(int i=0;i<=n-1;i++)
        s.insert(i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        auto p=s.lower_bound(a[i].second);
        if(p==s.end()||*p>a[i].first)
        {
            cout<<"NO"<<endl;
            return;
        }
        s.erase(p);
    }
    cout<<"YES"<<endl;
}
signed main()
{
    // freopen("road2.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
2
5
0 1 4 0 0
3 4 4 1 3
3
1 2 2
2 2 2
*/