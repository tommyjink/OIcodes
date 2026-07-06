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
    if(n%10==(n/10)%10&&n%10==n/100)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}