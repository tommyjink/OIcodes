#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int tmp=x+y+z;
        if(tmp%3)
        {
            cout<<"NO"<<endl;
            continue;
        }
        tmp/=3;
        if(x>tmp||y>tmp||z<tmp)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}