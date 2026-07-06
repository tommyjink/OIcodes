#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]>a[i])
            {
                cout<<"YES"<<endl;
                cout<<"2"<<endl;
                cout<<a[j]<<" "<<a[i]<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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