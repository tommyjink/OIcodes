//manacher马拉车
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e7;
string s,t="SS";
int mid,r,f[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    for(int i=0;i<s.length();i++)
        t+=s[i],t+='S';
    for(int i=1;i<t.length();i++)
    {
        if(i<r)f[i]=min(f[mid*2-i],r-i+1);
        while(t[i+f[i]]==t[i-f[i]])f[i]++;
        if(i+f[i]-1>=r)r=i+f[i]-1,mid=i;
        ans=max(ans,f[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}