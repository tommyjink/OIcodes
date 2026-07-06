#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

void solve()
{
    int a,x,y;
    cin>>a>>x>>y;
    if(x>y)swap(x,y);
    int dis0=abs(a-x),dis1=abs(a-y);
    for(int i=x;i<=y;i++)
    {
        if(abs(x-i)<dis0&&abs(y-i)<dis1)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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