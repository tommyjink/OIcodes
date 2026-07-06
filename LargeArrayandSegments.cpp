#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int a[N],sum[N];
void solve()
{
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum[i]=sum[i-1]+a[i];
    if(x>sum[n]*k)
    {
        cout<<"0"<<endl;
        return ;
    }
    while(x>sum[n])x-=sum[n],k--;
    int p=n;
    while(sum[n]-sum[p-1]<x)
        p--;
    cout<<(k-1)*n+p<<endl;
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