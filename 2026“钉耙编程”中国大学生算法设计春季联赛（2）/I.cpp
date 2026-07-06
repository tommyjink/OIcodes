#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m;
pii cal(int n)
{
    if(n==1)return {1,0};
    if(n==2)return {0,0};
    if(n&1)return {(n+1)/2,(n+1)/2-1};
    else return {((n-2)/2+1)/2*2,(n-2)-((n-2)/2+1)/2*2};
}// 1 0 1 0 0 0 0 1 0 1
// 1 0 0 0 0 1
void solve()
{
    cin>>n>>m;
    pii a=cal(n),b=cal(m);
    int res1=(m/2)*(a.first+a.second)+(m%2)*a.first;
    int res2=(n/2)*(b.first+b.second)+(n%2)*b.first;
    cout<<max(res1,res2)<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}