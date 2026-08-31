#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,a[N];
void solve()
{
    int cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)cnt++;
    }
    if(cnt==n)
    {
        if(n&1)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    else
    {
        if(cnt&1)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
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