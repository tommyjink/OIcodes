#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M=13,L=-1;
int ans=0;
map<int,int> mp;
int n,m,a[M];
void dfs(int x)
{
    // cout<<x<<endl;
    if(x<=L)return;
    if(mp.count(x))return;
    mp[x]=true;
    ans++;
    for(int i=1;i<=m;i++)
        dfs(x/a[i]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    dfs(n);
    cout<<ans<<endl;
    return 0;
}
