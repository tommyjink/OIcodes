#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,k,c[N],b[N];
pii a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second>>c[i];
    if(k==0)
    {
        sort(a+1,a+1+n);
        int now=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            now=max(now,a[i].first-1);
            ans+=a[i].second-now;
            now=max(now,a[i].second);
        }
        cout<<m-ans<<endl;
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
            b[a[i].first]+=c[i];
        sort(b+1,b+1+m);
        int ans=0,now=k;
        for(int i=1;i<=m;i++)
            if(now>=b[i])
                now-=b[i],ans++;
        cout<<ans<<endl;
    }
    return 0;
}