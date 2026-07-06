#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,val[N],tot=0,num[N];
vector<int> e[N];
map<int,int> mp[N];
vector<int> V[N];
bool cmp(int x,int y)
{
    return val[x]==val[y]?x<y:val[x]<val[y];
}
void dfs(int x,int fa)
{
    // cout<<x<<endl;
    for(auto i:V[x])
        if(i)cout<<i<<" ";
    for(int v:e[x])
    {
        if(v==fa)continue;
        dfs(v,x);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    num[0]=++tot;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(!mp[num[x]].count(y))
        {
            mp[num[x]][y]=++tot;
            e[num[x]].emplace_back(tot);
        }
        int now=mp[num[x]][y];
        // cout<<num[x]<<"___"<<now<<endl;
        num[i]=now;
        val[now]=y;
        V[now].emplace_back(i);
        // cout<<now<<","<<i<<endl;
    }
    for(int i=1;i<=tot;i++)
        sort(e[i].begin(),e[i].end(),cmp);
    // cout<<num[0]<<endl;
    dfs(num[0],num[0]);
    return 0;
}