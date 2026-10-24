#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    b[++m]=0;
    b[++m]=1e9+10;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int ans=0;
    for(int i=1;i<=m-1;i++)
    {
        int l=upper_bound(a+1,a+1+n,b[i])-a;
        int r=lower_bound(a+1,a+1+n,b[i+1])-a-1;
        ans=max(ans,r-l+1);
    }
    if(ans)cout<<ans<<endl;
    else cout<<"Impossible"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}