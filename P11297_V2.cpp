#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2005;
int S,n,dp[N];
vector<pii> w[N]; 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        w[y].push_back({x,z});
    }
    for(int i=1;i<=S;i++)
    {
        sort(w[i].begin(),w[i].end(),greater<pii>());
        vector<int> v;
        for(pii j:w[i])
        {
            int cnt=j.second;
            while(cnt&&v.size()<S/i)
                cnt--,v.push_back(j.first);
        }
        for(int j:v)
            for(int k=S;k>=i;k--)
                dp[k]=max(dp[k],dp[k-i]+j);
    }
    int ans=0;
    for(int i=1;i<=S;i++)ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}