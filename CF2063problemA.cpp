#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x==1&&y==1)
            cout<<"1"<<endl;
        else cout<<y-x<<endl;
    }
    return 0;
}