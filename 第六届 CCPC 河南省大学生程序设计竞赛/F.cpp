#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,ans=0;
bool check(string s)
{
    if(s.length()!=5)return false;
    if(s[0]!=s[1]&&s[0]!=s[2]&&s[0]!=s[3])
        if(s[1]!=s[2]&&s[1]!=s[3])
            if(s[2]!=s[3])
                if(s[2]==s[4])
                    return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(check(s))ans++;
    }
    cout<<ans<<endl;
    return 0;
}