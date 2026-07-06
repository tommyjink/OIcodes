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
        int a,b;
        cin>>a>>b;
        if(b==a+1||(a>b&&(a-b+1)%9==0))
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}