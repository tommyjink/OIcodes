#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
map<string,bool> mp;
int ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(!mp.count(s))ans++;
        mp[s]=1;
    }
    cout<<ans<<endl;
    return 0;
}