#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,w,f[N];
int a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>w;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    int ans=0;
    for(int i=1;i<(1ll<<n);i++)
    {
        int sum=0,tot=0;
        for(int j=1;j<=n;j++)
        {
            if(i&(1ll<<(j-1)))sum+=a[j],tot+=b[j];
        }
        if(tot<=w)ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}