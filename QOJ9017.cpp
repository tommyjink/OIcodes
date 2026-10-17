#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,dfn[N],low[N],in[N];
int f[N][N],col[N],ff[N][N];
int tot=0,num=0;
vector<int> g[N],e[N];
vector<int> V[N];
stack<int> s;
void tarjan(int x)
{
    dfn[x]=low[x]=++tot;
    in[x]=true;
    s.push(x);
    for(int v:g[x])
    {
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==x)
    {
        num++;
        while(1)
        {
            int t=s.top();s.pop();
            in[t]=false;
            col[t]=num;
            V[num].push_back(t);
            if(t==x)break;
        }
    }
}
vector<int> topo(int n,vector<int> *g,int *in)
{
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        for(int v:g[t])
        {
            if(!--in[v])
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            int x;cin>>x;
            if(x)f[j][i]=1;
            else f[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j])g[i].push_back(j);
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         cout<<
    for(int i=1;i<=n;i++)
        in[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j]&&col[i]!=col[j])
                ff[col[i]][col[j]]=1;
    
    return 0;
}