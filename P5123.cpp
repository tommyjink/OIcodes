#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n;
vector<int> a[N];
map<vector<int>,int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int ans=n*(n-1)/2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            int x;cin>>x;
            a[i].push_back(x);
        }
        sort(a[i].begin(),a[i].end());
        for(int j=1;j<(1ll<<5);j++)
        {
            vector<int> now;
            for(int k=0;k<5;k++)
                if(j&(1ll<<k))now.push_back(a[i][k]);
            if(!mp.count(now))mp[now]=0;
            mp[now]++;
            int cnt=mp[now];
            if(now.size()&1)ans-=cnt-1;
            else ans+=cnt-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}