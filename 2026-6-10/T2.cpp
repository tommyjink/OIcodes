#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,INF=1e18;
int n,a[N],l[N],r[N];
int f[N],fl[N],fr[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>l[i]>>r[i];
    f[0]=0;
    fl[0]=fr[0]=INF;
    for(int i=n;i>=1;i--)
    {
        if(!a[i])
        {
            f[i]=f[l[i]]+f[r[i]];
            fl[i]=fr[i]=INF;
        }
        else
        {
            fl[i]=min(f[l[i]],fl[l[i]])+f[r[i]];
            fr[i]=f[l[i]]+min(f[r[i]],fr[r[i]]);
            f[i]=1+min(f[l[i]],fl[l[i]])+min(f[r[i]],fr[r[i]]);
        }
    }
    cout<<f[1]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
