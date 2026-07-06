#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],cnt[N],tot=0,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>0)tot++;
    }
    while(tot>1)
    {
        sort(a+1,a+1+n);
        if(a[n]>0)
        {
            a[n]--;
            if(a[n]==0)tot--;
        }
        if(a[n-1]>0)
        {
            a[n-1]--;
            if(a[n-1]==0)tot--;
        }
        ans++;
        // for(int i=1;i<=n;i++)
        //     cout<<a[i]<<" ";
        // cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}