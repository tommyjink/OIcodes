#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,y,a[N],b[N],c[N],h[N];
map<int,int> mp;
void add(int x,int y)
{
    if(!mp.count(x))mp[x]=0;
    mp[x]+=y;
}
void solve()
{
    cin>>n>>x>>y;
    mp.clear();
    int t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        c[i]=max(0ll,h[i-1]-(a[i]-a[i-1]));
        h[i]=max(b[i],c[i]);
        if(b[i]<=c[i])continue;
        else
        {
            add(c[i],-1);
            add(b[i],1);
        }
    }   
    int base=0;
    for(int i=1;i<=n;i++)
        base+=max(0ll,b[i]-c[i]);
    int lst=0,slope=0,ans=base*y;
    for(auto [M,cnt]:mp)
    {
        base=base+(M-lst)*slope;
        ans=min(ans,M*x+base*y);
        lst=M,slope+=cnt;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}