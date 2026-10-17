#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],siz[N],tag[N],dep[N];
vector<int> e[N];
void dfs(int x,int fa)
{
    siz[x]=1;
    dep[x]=dep[fa]+1;
    tag[x]+=tag[fa];
    for(int v:e[x])
    {
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i]>>b[i];
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    dfs(1,0);
    for(int i=1;i<=n-1;i++)
    {
        if(dep[a[i]]>dep[b[i]])swap(a[i],b[i]);
        int tmp=siz[1]-siz[b[i]];
        if(tmp>siz[b[i]])
        {
            tag[1]+=i;
            tag[b[i]]-=i;
        }
        else
        {
            tag[b[i]]+=i;
        }
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        cout<<tag[i]<<" ";
    cout<<endl;
    return 0;
}