#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k;
//p=p+ceil(p/(k-1))

void solve()
{
    cin>>n>>k;
    int p=1;
    while(1)
    {
        int now=(p+k-2)/(k-1);
        int r=now*(k-1),cnt=(r-p)/now+1;
        // cout<<p<<","<<r<<endl;
        int t=p+(cnt*now);
        if(t<=n)p=t;
        else 
        {
            t=p+((n-p)/now)*now;
            cout<<t<<endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}