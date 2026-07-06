#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],vis[N];
string s;
void solve()
{
    int ans=0;
    cin>>n>>s;
    for(int i=0;i<=n+1;i++)vis[i]=a[i]=false;
    for(int i=0;i<n;i++)
        a[i+1]=s[i]-'0',ans+=a[i+1];
    for(int i=1;i<=n;i++)
        if(a[i]||a[i-1]||a[i+1])
            vis[i]=true;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int j=i;
        while(!vis[j]&&j<=n)j++;
        j--;
        // cout<<i<<","<<j<<endl;
        int len=j-i+1;
        ans+=(len+2)/3;
        i=j;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}