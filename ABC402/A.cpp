#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s,a;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    for(int i=0;i<s.length();i++)
        if(s[i]>='A'&&s[i]<='Z')
            a.push_back(s[i]);
    cout<<a<<endl;
    return 0;
}