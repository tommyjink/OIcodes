#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    for(int i=0;i<s.length()/2;i++)cout<<s[i];
    for(int i=s.length()/2+1;i<s.length();i++)cout<<s[i];
    return 0;
}