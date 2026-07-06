#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=50;
int n,t,a[N],ans=0;
vector<int> b;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<(1<<(n/2));i++)
    {
        int cnt=0;
        for(int j=1;j<=n/2;j++)
            if(i&(1<<(j-1)))
                cnt+=a[j];
        b.push_back(cnt);
    }
    // for(int i:b)
    //     cout<<i<<endl;
    sort(b.begin(),b.end());
    for(int i=0;i<(1<<(n-n/2));i++)
    {
        int cnt=0;
        for(int j=1;j<=n-n/2;j++)
            if(i&(1<<(j-1)))
                cnt+=a[j+n/2];
        if(cnt>t)continue;
        int p=upper_bound(b.begin(),b.end(),t-cnt)-b.begin()-1;
        if(cnt+b[p]<=t)
            ans=max(ans,cnt+b[p]);
    }
    cout<<ans<<endl;
    return 0;
}