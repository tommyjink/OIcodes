//T590214
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s;
int ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    for(int i=0;i<s.length();i++)
        if(s[i]>='A'&&s[i]<='Z')
            s[i]=s[i]-'X'+'x';
    for(int i=1;i<s.length();i++)
        if(s[i-1]=='x'&&s[i]=='p')
            ans++;
    cout<<ans<<endl;
    return 0;
}