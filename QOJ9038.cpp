#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,a[N],now=1;
set<int> s[N];
vector<int> e[N];
vector<pii> ans;
void dfs(int x)
{
    now++;
    for(auto v:e[x])
        s[v].erase(x);
    while(!s[x].empty()&&now<=n)
    {
        if(s[x].find(a[now])==s[x].end())
            ans.emplace_back(pii(x,a[now]));
        else  s[x].erase(a[now]);
        dfs(a[now]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        s[x].insert(y);
        e[x].push_back(y);
        s[y].insert(x);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(now<=n)dfs(a[now]);
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans)cout<<x<<" "<<y<<endl;
    return 0;
}