#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,x=-1e9,y;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>y;
        if(y<=x)
        {
            cout<<"No"<<endl;
            return 0;
        }
        x=y;
    }
    cout<<"Yes"<<endl;
    return 0;
}