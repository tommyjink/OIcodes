#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a,n,x;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>n>>x;
    int l=(a/x)*x+x,r=(n/x)*x;
    // cout<<l<<" "<<r<<endl;
    cout<<a+r/x-l/x+1;
    return 0;
}