#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],mx=0,c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
        c[i]=max(c[i+1],a[i]);
    int ans=0,now=0;
    for(int i=2;i<=n;i++)
    {
        if(now<c[i])now++,ans++;
        else if(now>c[i])now--,ans++;
        else ans++;
        while(now<a[i])now++,ans++;
    }
    cout<<ans+now<<endl;
    return 0;
}