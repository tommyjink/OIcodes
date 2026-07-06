#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y;
    cin>>x>>y;
    int t=abs(x-y);
    if(t==0)cout<<"1";
    else if(t%2)cout<<"2";
    else cout<<"3";
    return 0;
}