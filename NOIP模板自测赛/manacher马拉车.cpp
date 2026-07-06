#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e7+10;
string t,s=" #";
int n,f[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    for(auto c:t)
        s+=c,s+="#";
    // cout<<s<<endl;
    n=s.length()-1;
    int mid=0,r=0;
    for(int i=1;i<=n;i++)
    {
        if(i<=r)f[i]=min(f[mid*2-i],r-i+1);
        while(s[i-f[i]]==s[i+f[i]])f[i]++;
        if(i+f[i]-1>=r)r=i+f[i]-1,mid=i;
        ans=max(ans,f[i]-1);
        // cout<<f[i]<<" ";
    }
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}