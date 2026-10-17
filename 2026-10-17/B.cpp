#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    set<int> s;
    int ans=0;
    for(int i=1;i<=n;i++,ans++)
    {
        // for(int j:s)cout<<j<<","<<endl;
        s.insert(a[i]);
        if(s.empty())
        {
            int j=i+1;
            while(j<=n&&a[j]>=a[j-1])
                s.insert(a[j]),j++;
            // cout<<i<<","<<j-1<<endl;
            i=j-1;
            continue;
        }
        auto p=s.upper_bound(a[i]);
        int r=1e15;
        if(p!=s.end())r=*p;
        int j=i+1;
        while(j<=n&&a[j]>=a[j-1]&&a[j]<=r)
            s.insert(a[j]),j++;
        // cout<<i<<" "<<j-1<<" "<<a[i]<<endl;
        i=j-1;
    }
    cout<<ans<<endl;
    return 0;
}