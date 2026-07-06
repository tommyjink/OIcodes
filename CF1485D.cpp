#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;cin>>x;
            if((i+j)&1)cout<<"720720"<<" ";
            else cout<<720720+x*x*x*x<<" ";
        }
        cout<<endl;
    }
    return 0;
}