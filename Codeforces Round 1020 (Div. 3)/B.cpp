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
        int n,x;
        cin>>n>>x;
        for(int i=0;i<x;i++)
            cout<<i<<" ";
        for(int i=n-1;i>=x;i--)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}