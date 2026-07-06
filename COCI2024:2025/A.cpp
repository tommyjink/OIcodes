#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
string s;
vector<int> pos;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)
        if(s[i]=='\\')
            pos.push_back(i);
    int i;
    for(i=0;i<(int)pos.size()-1;i++)
    {
        if(pos[i+1]-pos[i]==4)
            cout<<'w',i++;
        else cout<<'v';
    }
    if(i==(int)pos.size()-1)
        cout<<'v';
    return 0;
}