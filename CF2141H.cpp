#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,vis[N];
vector<int> g[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(i);
    int ans=n;
    while(!s.empty())
    {
        int u=*s.begin(),siz=s.size();
        s.erase(u);
        queue<int> q;
        q.push(u);
        while(!q.empty())
        {
            int t=q.front();q.pop();
            for(int v:g[t])vis[v]=t;
            vector<int> P;
            for(int v:s)if(vis[v]!=t)P.push_back(v),q.push(v);
            for(int v:P)s.erase(v);
        }
        ans=min(ans,siz-(int)s.size());
    }
    if(ans<=1)cout<<"0 0"<<endl;
    else cout<<ans-1<<" "<<n-1<<endl;
    return 0;
}