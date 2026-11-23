#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=21;
int n,a[N],b[N];
int cnt[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("B.in","r",stdin);
    // freopen("BB.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    int ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=1;j<=n;j++)
            cnt[j]=0;
        for(int j=1;j<=n;j++)
            if((i>>(j-1))&1)
                cnt[b[j]]++;
            else cnt[a[j]]++;
        int c0=0,c1=0,c2=0;
        for(int j=1;j<=n;j++)
            if(cnt[j]==0)c0++;
            else if(cnt[j]==1)c1++;
            else if(cnt[j]==2)c2++;
        if(c0==1&&c2==1&&c1==n-2)ans++;
    }
    cout<<ans<<endl;
    return 0;
}