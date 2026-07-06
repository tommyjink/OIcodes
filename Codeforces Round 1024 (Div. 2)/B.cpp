#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
void solve()
{
    int cnt=0,tot=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(abs(a[i])<abs(a[1]))cnt++;
        if(abs(a[i])>abs(a[1]))tot++;
    }
    if(cnt+1<=(n+1)/2||tot+1>=(n+1)/2)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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