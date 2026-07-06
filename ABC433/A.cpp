#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y,z;
    cin>>x>>y>>z;
    while((x+y-1)/y>z)
    {
        x++,y++;
    }
    if(x==z*y)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}