#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,dfn[N],V[N],num=0;
int head[N],tot=0;
vector<pii> rg;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    dfn[x]=++num,V[num]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
    rg.push_back({dfn[x],num});
}
void solve()
{
    cin>>n;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=0;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    sort(rg.begin(),rg.end());
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
/*

2 0
5
1 2
1 3
2 4
2 5
10101
7
1 2
1 3
2 4
2 5
3 6
3 7
1011101

learn my code style from the CPP folder
*/