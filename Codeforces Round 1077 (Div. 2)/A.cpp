#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
void solve()
{
    int n;
    cin>>n;
    int mid=(n+1)/2;
    cout<<mid<<" ";
    for(int i=1;i<=n/2;i++)
    {
        if(mid+i<=n)cout<<mid+i<<" ";
        if(mid-i>=1)cout<<mid-i<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}