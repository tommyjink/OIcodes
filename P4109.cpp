#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int low(int x)
{
    int res=10;
    while(x%res==0)res*=10;
    return res/10;
}
int cal(int x)
{
    while(x%10==0)x/=10;
    int cnt=0,xx=x;
    while(x)x/=10,cnt++;
    if(xx%10==5)return cnt*2-1;
    else return cnt*2;
}
void solve()
{
    int L,R;
    cin>>L>>R;
    int x=L,res=1e10-1;
    while(x<=R)
    {
        if(cal(x)<cal(res))res=x;
        x+=low(x);
    }
    cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}