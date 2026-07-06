#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],l[N],r[N],fa[N];
int siz[N],lmx[N],rmx[N],f[N];
void dfs(int x)
{
    siz[x]=lmx[x]=rmx[x]=a[x];
    if(l[x])dfs(l[x]),siz[x]+=siz[l[x]];
    if(r[x])dfs(r[x]),siz[x]+=siz[r[x]];
    if(a[x])
    {
        lmx[x]=lmx[l[x]]+1;
        rmx[x]=rmx[r[x]]+1;
    }
    f[x]=f[l[x]]+f[r[x]]+a[x];
    if(!a[x])return;
    if(lmx[l[x]]==siz[l[x]])f[x]-=f[l[x]];
    if(rmx[r[x]]==siz[r[x]])f[x]-=f[r[x]];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
    dfs(1);
    for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    cout<<endl;
    cout<<f[1]<<endl;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}