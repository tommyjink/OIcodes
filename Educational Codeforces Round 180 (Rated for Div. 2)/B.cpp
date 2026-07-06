#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        if(abs(a[i]-a[i+1])<=1)
        {
            cout<<"0"<<endl;
            return;
        }
    }
    if(n==2)
    {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=2;i<=n-1;i++)
    {
        int x=min(a[i-1],a[i]);
        int y=max(a[i-1],a[i]);
        if(x<=a[i+1]&&a[i+1]<=y)
        {
            cout<<"1"<<endl;
            return;
        }
    }
    for(int i=2;i<=n-1;i++)
    {
        int x=min(a[i],a[i+1]);
        int y=max(a[i],a[i+1]);
        if(x<=a[i-1]&&a[i-1]<=y)
        {
            cout<<"1"<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
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