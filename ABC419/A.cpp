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
    if(s=="red")cout<<"SSS";
    else if(s=="blue")cout<<"FFF";
    else if(s=="green")cout<<"MMM";
    else cout<<"Unknown";
    return 0;
}