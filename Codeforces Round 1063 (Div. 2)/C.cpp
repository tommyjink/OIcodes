#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[2][N],b[2][N],d[N];
pii c[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
        d[i]=2*n+1;
    for(int i=1;i<=n;i++)
        cin>>a[0][i],b[0][i]=a[0][i];
    for(int i=1;i<=n;i++)
        cin>>a[1][i],b[1][i]=a[1][i];
    for(int i=2;i<=n;i++)
        a[0][i]=min(a[0][i],a[0][i-1]),
        b[0][i]=max(b[0][i],b[0][i-1]);
    for(int i=n-1;i>=1;i--)
        a[1][i]=min(a[1][i],a[1][i+1]),
        b[1][i]=max(b[1][i],b[1][i+1]);
    for(int i=1;i<=n;i++)
        c[i].first=min(a[0][i],a[1][i]),
        c[i].second=max(b[0][i],b[1][i]);
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)
        d[c[i].first]=min(d[c[i].first],c[i].second);
    for(int i=2*n-1;i>=1;i--)
        d[i]=min(d[i],d[i+1]);
    // for(int i=1;i<=2*n;i++)
    //     cout<<d[i]<<" ";
    // cout<<endl;
    int ans=0;
    for(int i=1;i<=2*n;i++)
    {
        if(d[i]>2*n)continue;
        ans+=(2*n-d[i]+1);
    }
    cout<<ans<<endl;
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