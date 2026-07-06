#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin>>a>>b;
    if(a+b==0||a+b==2)cout<<"Invalid";
    else if(a)cout<<"Yes";
    else cout<<"No";
    return 0;
}