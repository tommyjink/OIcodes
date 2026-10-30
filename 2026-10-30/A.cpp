#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n;
string s;
int ans=1;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    if(s.length()!=n)cout<<"error!"<<endl,exit(0);
    for(char c:s)if(c=='r')ans++;
    cout<<ans<<endl;
    return 0;
}