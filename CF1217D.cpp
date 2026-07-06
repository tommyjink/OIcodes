#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=5010;
int n,m,dfn[N],low[N],num=0,cnt=0;
int head[N],tot=0,st[N],top=1,col[N];
pii a[N]; 
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x)
{
    st[top++]=x;
    dfn[x]=low[x]=++num;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            dfs(v);
            low[x]=min(low[x],low[v]);
        }
        else if(!col[v])
        {
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x])
    {
        cnt++;
        while(1)
        {
            int t=st[--top];
            col[t]=cnt;
            if(t==x)break;
        }
    }
}
bool check()
{
    for(int i=1;i<=n;i++)
        if(!dfn[i])dfs(i);
    return cnt==n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].first>>a[i].second;
        add(a[i].first,a[i].second);
    }
    if(check())
    {
        cout<<"1"<<endl;
        for(int i=1;i<=m;i++)
            cout<<"1 ";
        return 0;
    }
    else
    {
        cout<<"2"<<endl;
        for(int i=1;i<=m;i++)
            if(a[i].first>a[i].second)cout<<"1 ";
            else cout<<"2 ";
    }
    return 0;
}