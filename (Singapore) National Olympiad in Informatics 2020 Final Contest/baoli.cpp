#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],now=0,ans=0,cnt=0,mx=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        now+=a[i];
        ans+=now;
        int res1=cnt*mx+(mx+a[i])+(mx+a[i])*(n-i);
        int res2=(cnt+1)*max(mx,a[i])+max(mx,a[i])*(n-i);
        // cout<<i<<":"<<res1<<","<<res2<<endl;
        if(i==1||res1<res2)
            mx=a[i],cnt=1;
        else mx=max(mx,a[i]),cnt++,ans-=res1-res2;
    }
    cout<<ans<<endl;
    return 0;
}