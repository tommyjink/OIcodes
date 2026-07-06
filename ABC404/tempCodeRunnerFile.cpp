#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int tag[1000];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
        tag[s[i]]=true;
    for(int i='a';i<='z';i++)
        if(!tag[i])cout<<(char)i<<endl;
    
    return 0;
}