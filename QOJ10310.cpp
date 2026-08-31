#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=55;
int n,m;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cout<<"YES"<<endl;
    cout<<2*m<<endl;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<a<<" "<<b<<" ";
        for(int j=1;j<=n;j++)
            if(j!=a&&j!=b)cout<<j<<" ";
        cout<<endl;
        for(int j=n;j>=1;j--)
            if(j!=a&&j!=b)cout<<j<<" ";
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}