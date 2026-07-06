#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
string s;
int solve()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n-1;i++)
    {
        if(s[i]=='*'&&s[i+1]=='<')return -1;
        if(s[i]=='>'&&s[i+1]=='*')return -1;
        if(s[i]=='*'&&s[i+1]=='*')return -1;
        if(s[i]=='>'&&s[i+1]=='<')return -1;
    }
    for(int i=1;i<=n;i++)
        if(s[i]=='*')
            return max(i,n-i+1);
    for(int i=1;i<=n-1;i++)
        if(s[i]=='<'&&s[i+1]=='>')
            return max(i,n-i);
    return n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
    return 0;
}