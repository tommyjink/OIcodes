#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    if(k&1)
    {
        for(int i=1;i<=n-1;i++)
            cout<<n<<" ";
        cout<<n-1<<endl;
        return;
    }
    else
    {
        for(int i=1;i<=n-2;i++)
            cout<<n-1<<" ";
        cout<<n<<" "<<n-1<<endl;
        return;
    }
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