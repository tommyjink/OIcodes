#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

void solve()
{
    int x;
    cin>>x;
    int i=0;
    while(++i)
    {
        if(x%i==0&&(x/i)%2==1)
        {
            cout<<i+1<<endl;
            break;
        }
    }
    return;
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