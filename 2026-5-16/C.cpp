#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20,P=1e9+7;
int n,k,h[N],a[N],b[N],c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    int ans=0;
    for(int s=0;s<(1ll<<n);s++)
    {
        if(__builtin_popcountll(s)!=k)continue;
        for(int i=1;i<=n;i++)
            if(s&(1ll<<(i-1)))a[i]=0;
            else a[i]=h[i];
        for(int i=1;i<=n+1;i++)
            b[i]=c[i]=0;
        for(int i=1;i<=n;i++)
            b[i]=max(b[i-1],a[i]);
        for(int i=n;i>=1;i--)
            c[i]=max(c[i+1],a[i]);
        int res=0;
        for(int i=1;i<=n;i++)
        {
            res+=min(b[i],c[i])-a[i];
        }
        if(res%2==0)
        {
            // cout<<res<<","<<s<<":"<<endl;
            // for(int i=1;i<=n;i++)
            //     cout<<a[i]<<" ";
            // cout<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}