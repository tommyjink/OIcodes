#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],c[N],t;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1){cout<<"0"<<endl;return;}
    for(int i=1;i<=n/2;i++)a[i]=(a[i]-a[n-i+1]+m)%m;
    n=n/2+1;a[n]=0;
    for(int i=1;i<=n;i++)b[i]=(a[i]-a[i-1]+m)%m;
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)c[i]=m-b[i];
    for(int i=2;i<=n;i++)b[i]+=b[i-1];
    for(int i=n-1;i>=1;i--)c[i]+=c[i+1];
    for(int i=1;i<=n;i++)if(b[i]==c[i+1]){cout<<b[i]<<endl;return;}
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)solve();
    return 0;
}