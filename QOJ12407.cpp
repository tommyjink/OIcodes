#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=200;
int n,a[N],id[N];
vector<int> e[N];
vector<int> L,R;
void dfs(int x,int fa,int dep)
{
    if(dep&1)L.push_back(x);
    else R.push_back(x);
    for(auto v:e[x])
    {
        if(v==fa)continue;
        dfs(v,x,dep+1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=(1ll<<60)-1;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0,1);
    if(L.size()>R.size())swap(L,R);
    for(auto x:L)a[x]^=(1ll<<59);
    for(auto x:R)a[x]=(1ll<<59);
    int cnt=0;
    for(auto x:L)
    {
        id[x]=++cnt;
        a[x]^=(1ll<<cnt);
    }
    for(auto y:R)
    {
        for(auto x:e[y])
        {
            a[y]^=(1ll<<id[x]);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}