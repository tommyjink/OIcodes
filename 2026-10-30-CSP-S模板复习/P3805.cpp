#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=3e7+10;
int n=1,r[N];
string t;
char s[N]=" #";
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    for(char c:t)
        s[++n]=c,s[++n]='#';
    int R=0,mid=0,ans=0;
    // cout<<s<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i<=R)r[i]=min(R-i+1,r[mid*2-i]);
        while(s[i-r[i]]==s[i+r[i]])r[i]++;
        if(i+r[i]-1>R)R=i+r[i]-1,mid=i;
        ans=max(ans,r[i]-1);
        // cout<<i<<":"<<r[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}