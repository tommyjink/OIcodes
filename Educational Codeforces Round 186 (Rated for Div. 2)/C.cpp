#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],f[N],g[N];
inline int cal(int x)
{
    return (x-1)%n+1;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=true;
        for(int j=1;j<=n;j++)
            if(a[j]>=b[cal(i+j-1)])f[i]=false;
        cnt1+=f[i];
        // cout<<f[i]<<" ";
    }
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        g[i]=true;
        for(int j=1;j<=n;j++)
            if(b[j]>=c[cal(i+j-1)])g[i]=false;
        cnt2+=g[i];
        // cout<<g[i]<<" ";
    }
    // cout<<endl;
    cout<<cnt1*cnt2*n<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}