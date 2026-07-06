#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N*2],cnt[N];
map<pair<int,int> ,int> mp;
void solve()
{
    int ans=0;
    cin>>n;
    mp.clear();
    for(int i=1;i<=n*2;i++)
        cin>>a[i],cnt[a[i]]=0;
    a[n*2+1]=-1;
    for(int i=1;i<=n*2;i++)
    {
        // cin>>a[i];
        cnt[a[i]]++;
        if(i>1)
        {
            if(a[i-1]==a[i]||a[i]==a[i+1])continue;
            pair<int,int> tmp=make_pair(min(a[i-1],a[i]),max(a[i-1],a[i]));
            if(mp.count(tmp)&&mp[tmp]<=i-2)
                ans++;
            mp[tmp]=i;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
/*
3
3
1 2 3 3 1 2
4
1 1 2 2 3 3 4 4
5
1 2 3 4 5 1 2 3 4 5

*/