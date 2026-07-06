#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,ans=0;
map<pair<int,int>,int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        if(x==y||mp[make_pair(x,y)])
        {
            ans++;continue;
        }
        mp[make_pair(x,y)]=true;
    }
    cout<<ans<<endl;
    return 0;
}