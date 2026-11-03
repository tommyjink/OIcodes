#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5005;
int n,tot,head[N];
int q[N*20],num=0,st[N][21];
int dep[N],lg[N*20],pos[N];
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
    q[++num]=x;
    pos[x]=num;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        q[++num]=x;
    }
}
void init()
{
    for(int i=1;i<=num;i++)
        st[i][0]=q[i];
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=num-(1<<i)+1;j++)
        {
            if(dep[st[j][i-1]]<dep[st[j+(1<<(i-1))][i-1]])
                st[j][i]=st[j][i-1];
            else st[j][i]=st[j+(1<<(i-1))][i-1];
        }
    }
}
int query(int l,int r)
{
    if(l==r)return st[l][0];
    if(l>r)return -1;
    int d=lg[r-l+1];
    if(dep[st[l][d]]<dep[st[r-(1<<d)+1][d]])
        return st[l][d];
    return st[r-(1<<d)+1][d];
}
int lca(int x,int y)
{
    x=pos[x],y=pos[y];
    if(x>y)swap(x,y);
    return query(x,y);
}
void dfs1(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs1(v,x);
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    init();
    for(int i=1;i<=n;i++)
        for(int j=0;j<=2;j++)
            cout<<i<<" "<<j<<":"<<st[i][j]<<endl;
    while(1)
    {
        int x,y;
        cin>>x>>y; 
        cout<<lca(x,y)<<endl;
    }
    return 0;
}