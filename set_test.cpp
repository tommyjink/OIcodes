#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> s;
    auto i=s.insert(1).first;
    s.insert(2);
    if(i==s.begin())cout<<"!";
    if(++i==s.end())cout<<"!";
    cout<<*--s.end();
    return 0;
}