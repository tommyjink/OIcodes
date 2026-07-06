// Version2.0 of Lights.cpp
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=50;
int n,m,a[N],ans=1e10;
map<int,int> f;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        a[i]|=(1ll<<(i-1));
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]|=1ll<<(y-1);
        a[y]|=1ll<<(x-1);
    }
    for(int i=0;i<(1ll<<(n/2));i++)
    {
        int t=0,cnt=0;
        for(int j=1;j<=n/2;j++)
            if(i&(1ll<<(j-1)))
                cnt++,t^=a[j];
        if(!f.count(t))f[t]=cnt;
        else f[t]=min(f[t],cnt);
    }
    for(int i=0;i<(1ll<<(n-n/2));i++)
    {
        int t=0,cnt=0;
        for(int j=1;j<=(n-n/2);j++)
            if(i&(1ll<<(j-1)))
                cnt++,t^=a[n/2+j];
        if(f.count(((1ll<<n)-1)^t))
            ans=min(ans,f[((1ll<<n)-1)^t]+cnt);
    }
    cout<<ans<<endl;
    return 0;
}