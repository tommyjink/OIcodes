#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])continue;
        int now=i,cnt=1;
        while(now+1<=n&&a[now+1]==a[i])now++,cnt++;
        while(now<=n)
        {
            int p=lower_bound(a+now+1,a+1+n,a[now]*2-a[i])-a;
            if(p>n)break;
            now=p;
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<n-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}