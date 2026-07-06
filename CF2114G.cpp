#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10;
int n,k,a[N],b[N],dp1[N],dp2[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]/lowbit(a[i]);
        dp1[i]=dp2[i]=lowbit(a[i]);
    }
    for(int i=1;i<=n;i++)if(b[i]==b[i-1]&&a[i]>a[i-1])dp1[i]=(a[i]-2*a[i-1])/b[i]+1;
    for(int i=n;i>=1;i--)if(b[i]==b[i+1]&&a[i]>a[i+1])dp2[i]=(a[i]-2*a[i+1])/b[i]+1;
    for(int i=n;i>=1;i--)dp1[i]+=dp1[i+1];
    for(int i=1;i<=n;i++)dp2[i]+=dp2[i-1];
    int ans=max(dp2[n],dp1[1]);
    for(int i=1;i<=n;i++)ans=max(ans,dp2[i-1]+lowbit(a[i])+dp1[i+1]);
    if(k<=ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    for(int i=1;i<=n;i++)a[i]=b[i]=dp1[i]=dp2[i]=0;
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
/*
8
3 3
2 1 4
3 7
2 1 4
2 15
2 16
3 10
256 32 1
3 289
768 96 1
3 290
768 96 1
5 7
5 1 6 3 10
4 6
6 8 5 10


1
3 290
768 96 1

1
3 8
4 1 4
*/