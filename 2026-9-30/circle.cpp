#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e16;
int n,m,a[N],b[N],c[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]%=m;
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++)
        c[i]=c[i-1]+(m-1-a[i]);
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<m/2)
        {
            int r=upper_bound(a+1,a+1+n,a[i]+m/2)-a-1;
            int res=b[r]-b[i]-(r-i)*a[i];
            res+=c[i]-i*(m-1-a[i]);
            if(r!=n)res+=c[n]-c[r]+(a[i]+1)*(n-r);
            ans=min(ans,res);
            // cout<<i<<":"<<res<<","<<r<<","<<c[i]-i*(m-1-a[i])<<endl;
        }
        else
        {
            int l=lower_bound(a+1,a+1+n,a[i]-m/2)-a;
            int res=c[i]-c[l-1]-(i-l+1)*(m-1-a[i]);
            res+=b[n]-b[i]-a[i]*(n-i);
            if(l>1)res+=b[l-1]+(l-1)*(m-a[i]);
            ans=min(ans,res);
            // cout<<i<<":"<<res<<"!!"<<l<<","<<b[l-1]+(l-1)*(m-1-a[i])<<endl;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}