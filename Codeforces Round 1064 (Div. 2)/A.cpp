#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
string s;
void solve()
{
    cin>>n>>s;
    s=" "+s;
    int res=0;
    for(int i=1;i<=n;i++)
        if(s[i]!=s[n])res++;
    cout<<res<<endl;
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