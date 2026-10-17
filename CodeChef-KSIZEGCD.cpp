#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
vector<pii> g[2];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void solve()
{
    int now=0;
    g[1].clear(),g[2].clear();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=0;
    for(int i=1;i<=n;i++,now^=1)
    {
        g[now].clear();
        g[now].push_back({a[i],1});
        for(auto [val,len]:g[now^1])
        {
            if(gcd(val,a[i])==g[now].back().first)g[now].pop_back();
            g[now].push_back({gcd(val,a[i]),len+1});
        }
        for(auto [val,len]:g[now])b[len]=max(b[len],val);
    }
    for(int i=n-1;i>=1;i--)
        b[i]=max(b[i],b[i+1]);
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}