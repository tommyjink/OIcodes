#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=0;
    int mx=0;
    for(int i=2;i<=n;i++)
        b[i]=max(0ll,a[i-1]-a[i]),
        mx=max(mx,b[i]);
    if(n%2==0){cout<<mx<<endl;return;}
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        a[i]+=cnt*i;
        if(i&1)continue;
        int now=max(0ll,min(mx-cnt,(a[i+1]-a[i])/(i)));
        cnt+=now;
        a[i]+=now*i;
    }
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1]){cout<<"-1"<<endl;return;}
    cout<<mx<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}