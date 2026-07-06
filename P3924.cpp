#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==1||j==n)cout<<"|";
            else if(i==(n+1)/2)cout<<"-";
            else cout<<"a";
        }
        cout<<endl;
    }
    return 0;
}