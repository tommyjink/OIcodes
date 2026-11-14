#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,a[N],d[N],vis[N];
int dep[N];
vector<int> f[N],g[N];
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
void repo(){cout<<"-1"<<endl;exit(0);}
void dfs(int x,int fa)
{
    vis[x]=true;
    dep[x]=dep[fa]+1;
    for(int v:f[x])
    {
        if(vis[v])continue;
        dfs(v,x);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]++;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        for(int j=1;j<=d[i];j++)
        {
            int x;cin>>x;
            if(a[x]>a[i])f[i].push_back(x);
            else g[i].push_back(x);
        }
        sort(f[i].begin(),f[i].end(),cmp);
        for(int j:g[i])f[i].push_back(j);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            dfs(i,0);
            // for(int j=1;j<=n;j++)
            //     cout<<a[j]<<" ";
            // cout<<endl;
            // for(int j=1;j<=n;j++)
            //     cout<<dep[j]<<" ";
            // cout<<endl;
            for(int j=1;j<=n;j++)
                if(a[j]!=dep[j])repo();
            cout<<i<<endl;
            for(int j=1;j<=n;j++)
            {
                for(int k:f[j])cout<<k<<" ";
                cout<<endl;
            }
            return 0;
        }
    }
    repo();
    return 0;
}