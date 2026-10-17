#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,m;
vector<int> g[N];
struct node
{
    int x,y,l,r;
}a[N];
void dfs(int x,int fa)
{
    for(int v:g[x])
    {
        if(v==fa)continue;
        dfs(v,x);
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y>>a[i].l>>a[i].r;
    
    return 0;
}