#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],cnt[N];
void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],cnt[a[i]]++;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(cnt[i]&&cnt[i]<i)    
            ans+=cnt[i];
        else if(cnt[i]>i)
            ans+=cnt[i]-i;
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