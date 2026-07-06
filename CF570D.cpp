#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,head[N],tot;
int dep[N],siz[N],son[N],qdep[N];
int L[N],R[N],num,c[N],ans[N];
int cnt[30][N],col[N],odd[N];
vector<int> q[N];
struct node
{
    int to,next;
}e[N*2];
void addedge(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void add(int x)
{
    cnt[col[x]][dep[x]]++;
    if(cnt[col[x]][dep[x]]&1)odd[dep[x]]++;
    else odd[dep[x]]--;
}
void del(int x)
{
    cnt[col[x]][dep[x]]--;
    if(cnt[col[x]][dep[x]]&1)odd[dep[x]]++;
    else odd[dep[x]]--;
}
void dfs(int x,int fa)
{
    siz[x]=1,L[x]=++num;
    dep[x]=dep[fa]+1,c[num]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
        if(siz[v]>=siz[son[x]])
            son[x]=v;
    }
    R[x]=num;
}
void dfs1(int x,int fa,int keep)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==son[x])continue;
        dfs1(v,x,false);
    }
    if(son[x])dfs1(son[x],x,true);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==son[x])continue;
        for(int j=L[v];j<=R[v];j++)
            add(c[j]);
    }
    add(x);
    for(int i:q[x])
        if(odd[qdep[i]]<=1)ans[i]=true;
        else ans[i]=false;
    if(!keep)
        for(int i=L[x];i<=R[x];i++)
            del(c[i]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        addedge(i,x);
        addedge(x,i);
    }
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
        col[i]=s[i-1]-'a';
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x>>qdep[i];
        q[x].push_back(i);
    }
    dfs(1,0);
    dfs1(1,0,1);
    for(int i=1;i<=m;i++)
        if(ans[i])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    return 0;
}