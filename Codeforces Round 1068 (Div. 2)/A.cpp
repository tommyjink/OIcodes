#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N];
void solve()
{
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
        a[i]=s[i-1]-'0'+a[i-1];
    int res=0;
    for(int i=1;i<=n;i++)
        if(a[i]-a[max(0ll,i-k-1)]==0)res++;
    for(int i=1;i<=n;i++)a[i]=0;
    cout<<res<<endl;
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