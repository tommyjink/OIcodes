#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,y,a[N],b[N];
map<int,int> mp;
void solve()
{
    cin>>n>>x>>y;
    mp.clear();
    int t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        t=max(0ll,b[i-1]-(a[i]-a[i-1]));
        mp[t+1]-=y;
        mp[b[i]+1]+=y;
    }   
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}