#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int cal(int a,int b)
{
    for(int i=0;i<=30;i++)
    {
        if(i&1)a-=(1ll<<i);
        else b-=(1ll<<i);
        if(a<0||b<0)return i;
    }
}
void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<max(cal(a,b),cal(b,a))<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}