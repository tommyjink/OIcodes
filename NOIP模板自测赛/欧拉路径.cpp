#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,in[N],vis[N],out[N],lim[N];
vector<int> e[N],V;
void dfs(int x)
{
    while(!e[x].empty())
    {
        int v=e[x].back();
        e[x].pop_back();
        dfs(v);
    }
    V.emplace_back(x);
}
signed main()
{
    // freopen("P7771_1.in","r",stdin);
    // freopen("test.txt","w",stdout)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        in[y]++;
        out[x]++;
        e[x].emplace_back(y);
    }
    for(int i=1;i<=n;i++)
        sort(e[i].begin(),e[i].end(),greater<int>());
    int c1=0,c2=0,s=1;
    for(int i=1;i<=n;i++)
    {
        if(in[i]+1==out[i])c1++,s=i;
        else if(in[i]==out[i]+1)c2++;
        else if(in[i]!=out[i])cout<<"No"<<endl,exit(0);
    }
    if(!(c1==1&&c2==1)&&!(c1==0&&c2==0))
        cout<<"No"<<endl,exit(0);
    dfs(s);
    reverse(V.begin(),V.end());
    for(auto i:V)cout<<i<<" ";
    return 0;
}