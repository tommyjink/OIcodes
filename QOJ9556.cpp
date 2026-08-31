#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int> 
using namespace std;
const int N=1e6+10;
int n,deg[N];
vector<int> g[N];
vector<pii> ans;
int dfs(int x,int fa)
{
    queue<int> V;
    for(int v:g[x])
    {
        if(v==fa)continue;
        int res=dfs(v,x);
        if(res)V.push(res);
    }
    while(!V.empty())
    {
        int t=V.front();V.pop();
        if(V.empty())return t;
        int p=V.front();V.pop();
        ans.push_back({t,p});
    }
    return x;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        g[i].clear(),deg[i]=0;
    ans.clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    int tmp=0;
    for(int i=1;i<=n;i++)
        if(deg[i]%2==0)tmp=i;
    if(!tmp){cout<<"-1"<<endl;return;}
    dfs(tmp,0);
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans)cout<<x<<" "<<y<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}