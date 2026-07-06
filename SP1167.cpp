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
        int n;
        cin>>n;
        int a=(n-1)/3;
        int b=(n-1-a)/2;
        int c=n-1-a-b;
        cout<<(a*a+b*b+c*c+n-1)/2<<endl;
    }
    return 0;
}