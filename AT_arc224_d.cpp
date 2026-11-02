#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k;
int cal(int x)
{
    // cout<<x<<",";
    int cnt=0;
    while(x)cnt++,x/=10;
    // cout<<cnt<<endl;
    return cnt;
}
void solve()
{
    cin>>n>>k;
    k--;
    int now=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        now=now*(n-i+1)/i;
        // cout<<now<<"!"<<endl;
        int h=now;
        while(h--&&k--)ans+=i*cal(k+1);
        if(k==-1)break;
    }
    if(~k)cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}