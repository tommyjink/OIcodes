#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int T;
string s;
void solve()
{
    cin>>s;
    for(int i=3;i<s.length();i++)
    {
        if(s[i-3]=='2'&&s[i-2]=='0'&&s[i-1]=='2'&&s[i]=='4')
            s[i]='5';
    }
    cout<<s<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
        solve();
    return 0;
}