#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,nxt[N],ans=0,mn[N];
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
        mn[i]=mn[nxt[i]];
        if(!mn[i])mn[i]=nxt[i];
        // cout<<i<<","<<nxt[i]<<endl;
        if(mn[i])ans+=i-mn[i];
    }
    cout<<ans<<endl;
    return 0;
}