#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
void solve()
{
    cin>>n;
    if(!n)
    {
        cout<<endl;
        return;
    }
    if(n&1)
    {
        cout<<"-1"<<endl;
        return;
    }
    int num=(n-1)/4,num1=(n-num*2-2)/2;
    cout<<"(";
    for(int i=1;i<=num;i++)
        cout<<"()";
    cout<<")";
    for(int i=1;i<=num1;i++)
        cout<<"()";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}