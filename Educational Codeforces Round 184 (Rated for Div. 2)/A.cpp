#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],p;
void solve()
{
    cin>>n>>p;
    int ans1=0,ans2=0,ans3=0;
    int x=p-1,y=p,z=p+1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(abs(x-a[i])<abs(p-a[i]))
            ans1++;
        if(abs(y-a[i])<abs(p-a[i]))
            ans2++;
        if(abs(z-a[i])<abs(p-a[i]))
            ans3++;
    }
    if(ans1>max(ans2,ans3))cout<<x<<endl;
    else if(ans2>ans3)cout<<y<<endl;
    else cout<<z<<endl;
    
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