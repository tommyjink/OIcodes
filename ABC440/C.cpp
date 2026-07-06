#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],w;
vector<int> l;
void solve()
{
    l.clear();
    cin>>n>>w;
    int ans=1e18,now=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%(w*2)<w)
            now+=a[i];
    }
    // cout<<now<<endl;
    for(int x=1;x<=2*w;x++)
    {
        for(int i=0;i-x<=n;i+=2*w)
        {
            //i~i+w-1
            if(i-x>0&&i-x<=n)now+=a[i-x];
            if(i+w-x>0&&i+w-x<=n)now-=a[i+w-x];
            // cout<<i-x<<","<<i+w-x<<" "<<now<<"!"<<endl;
        }
        // cout<<now<<" x:"<<x<<endl;
        ans=min(ans,now);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}