#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,cnt=0,a[N],f[N],r,mid,g[N],ans=0;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    a[++cnt]=3;
    a[++cnt]=3;
    int now=0;
    for(auto c:s)
    {
        if(c-'0')a[++cnt]=1^now;
        else a[++cnt]=0^now;
        a[++cnt]=3;
        now^=1;
    }
    for(int i=1;i<=cnt;i++)
    {
        if(a[i]!=3)continue;
        if(i<r)f[i]=min(f[mid*2-i],r-i+1);
        if(i<r)g[i]=min(g[mid*2-i],r-i+1);
        while(a[i+f[i]]==a[i-f[i]])f[i]++;
        // while((a[i+g[i]]+a[i-g[i]]==1)||(a[i+g[i]]+a[i-g[i]]==6))g[i]++;
        if(i+f[i]-1>=r)r=i+f[i]-1,mid=i;
        ans+=(f[i]-1)/2;
    }
    // for(int i=1;i<=cnt;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}