#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,head[N],dep[N],L[N],R[N];
int tot=0,cnt=0,q,f[N][30];
vector<int> v[N];
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
    L[x]=++cnt,dep[x]=dep[fa]+1;
    f[x][0]=fa;
    v[dep[x]].emplace_back(cnt);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
    R[x]=cnt;
}
void init()
{
    for(int i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<25;i++)
        for(int j=1;j<=n;j++)   
            f[j][i]=f[f[j][i-1]][i-1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n-1;i++)
    {
        int x;
        cin>>x;
        add(i+1,x);
        add(x,i+1);
    }
    dfs(1,0);
    init();
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(dep[x]<=y)
        {
            cout<<"0 ";
            continue;
        }
        int d=dep[x];
        for(int i=24;i>=0;i--)
            if((1<<i)<=y)
                y-=(1<<i),x=f[x][i];
        int p1=lower_bound(v[d].begin(),v[d].end(),L[x])-v[d].begin();
        int p2=upper_bound(v[d].begin(),v[d].end(),R[x])-v[d].begin()-1;
        cout<<p2-p1<<" ";
    }
    return 0;
}