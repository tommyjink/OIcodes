#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
signed main()
{
    // freopen("./mod/mod3.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        int ans=a[n]-a[1];
        n=unique(a+1,a+1+n)-a-1;
        if(n>2)ans=max(ans,a[n-1]);
        cout<<ans<<endl;
    }
    return 0;
}