#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        long double n,pi=3.1415926535897932384626;
        cin>>n;
        cout<<(int)(n*(1.0-6.0/pi/pi))<<endl;
    }
    return 0;
}