#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,k,cnt[N];
pii a[N];
int up(int x,int y)
{
    return (x+y-1)/y;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int c,w,f;
        cin>>c>>w>>f;
        a[i]={f,c*w};
    }
    sort(a+1,a+1+n,greater<pii>());
    int ans=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        int x=up(sum,k),y=up(sum+a[i].second,k);
        ans+=a[i].first*(y-x);
        sum+=a[i].second;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}