#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
void f(int a)
{
    if(a&(1ll<<2))cout<<"r";
    else cout<<"-";
    if(a&(1ll<<1))cout<<"w";
    else cout<<"-";
    if(a&(1ll<<0))cout<<"x";
    else cout<<"-";
}
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
        int a=n%10;
        int b=(n%100)/10;
        int c=n/100;
        f(c),f(b),f(a);
        cout<<endl;
    }
    return 0;
}