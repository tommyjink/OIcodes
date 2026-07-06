#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,k,a[N],b[N];
vector<int> v;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
int F(int x)
{
    return qpow(x,P-2);
}
void dfs(int l,int r,int now)
{
    if(now==0)v.push_back(r-l+1);
    if(l>=r||now==0)return;
    int mid=(l+r)>>1;
    dfs(l,mid,now-1);
    dfs(mid+1,r,now-1);
}
void solve()
{ 
    cin>>n>>k;
    v.clear();
    dfs(1,n,k);
    // for(auto i:v)cout<<i<<" ";
    // cout<<endl;
    int ans=a[n];
    for(auto i:v)ans=ans*b[i]%P;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a[0]=1,b[0]=1;
    for(int i=1;i<N;i++)a[i]=a[i-1]*i%P;
    for(int i=1;i<N;i++)b[i]=b[i-1]*F(i)%P;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}