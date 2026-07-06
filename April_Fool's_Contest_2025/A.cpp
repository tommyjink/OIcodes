#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int x;
    while(cin>>x)
    {
        if(x==0)
            ans--;
        else ans++;
        ans=max(ans,0ll);
    }
    cout<<ans<<endl;
    return 0;
}