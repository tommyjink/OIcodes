#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,k;
multiset<int> s;
struct node
{
    int x,y;
}a[N];
bool cmp(node x,node y)
{
    return x.y>y.y;
}
void solve()
{
    int ans=0;
    s.clear();
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        k-=y;
        a[i]=(node){x,z-y};
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        auto p=s.lower_bound(a[i].x);
        if(p==s.end())continue;
        a[i].x=a[i].y=0;
        s.erase(p);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=n;i>=1;i--)
        if(k>=a[i].y)k-=a[i].y,ans++;
    cout<<ans<<endl;
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