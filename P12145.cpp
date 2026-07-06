#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n=0,tot=0,top=0,cnt=0;
int num=0,ccol=0,ans=0,sum=0,now=0;
int dfn[N],low[N],colcnt[N],t[N],vis[N];
int stk[N],col[N],head[N],tag[N*2];
int f1[N],f2[N],g[N],s[N],f[N],p[N];
vector<int> circle;
struct node
{
    int to,next,from;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
void tarjan(int x,int fa)
{
    dfn[x]=low[x]=++num;
    stk[top++]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(!dfn[v])tarjan(v,x),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        while(1)
        {
            int v=stk[--top];
            col[v]=cnt;
            colcnt[cnt]++;
            if(colcnt[cnt]>1)ccol=cnt;
            if(v==x)break;
        }
    }
}
void dfs1(int x,int fa)
{
    vis[x]=true;
    circle.emplace_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(vis[v]||v==fa)continue;
        if(col[v]==ccol)dfs1(v,x);
    }
}
void dfs(int x,int fa)
{
    int son1=0,son2=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||tag[i])continue;
        dfs(v,x);
        if(f1[v]>=f1[son1])son1=v;
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||tag[i]||v==son1)continue;
        if(f1[v]>=f1[son2])son2=v;
    }
    f1[x]=f1[son1]+t[x];
    f2[x]=f1[son2]+t[x];
    g[x]=f1[son1]+f1[son2]+t[x];
    ans=max(ans,g[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i,0);
    for(int i=1;i<=tot;i++)
        if(col[e[i].from]==col[e[i].to])
            tag[i]=1;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==ccol)
        {
            dfs1(i,0);
            break;
        }
    }
    for(auto i:circle)
        dfs(i,0),sum+=t[i];
    for(auto i:circle)
        ans=max(ans,g[i]+sum-t[i]);
    int m=colcnt[ccol];
    for(int i=1;i<=m;i++)
        s[i]=t[circle[i-1]],f[i]=f1[circle[i-1]];
    for(int i=m+1;i<=2*m;i++)
        s[i]=s[i-m],f[i]=f[i-m];
    for(int i=1;i<=2*m;i++)
        s[i]+=s[i-1],p[i]=f[i]-s[i];
    // for(int i=1;i<=2*m;i++)
    //     cout<<s[i]<<","<<f[i]<<endl;
    deque<int> dq;
    for(int i=1;i<=2*m;i++)
    {
        while(!dq.empty()&&dq.front()<=i-m)dq.pop_front();
        if(!dq.empty())ans=max(ans,s[i-1]+f[i]+p[dq.front()]);
        while(!dq.empty()&&p[dq.back()]<=p[i])dq.pop_back();
        dq.push_back(i);
    }
    cout<<ans<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<i<<":"<<g[i]<<endl;
    return 0;
}
/*

9
1 0 1 0 0 1 1 0 1
2 8
2 9
2 5
1 5
1 3
1 4
4 6
6 7
5 8


i,j belong circle
val=dis(i,j)+f1[i]+f1[j]

 s[i]-s[j-1]+f1[i]+f1[j]-t[i]-t[j]
=s[i]+f1[i]-t[i]+(f1[j]-t[j]-s[j-1])
=s[i-1]+f1[i]+(f1[j]-s[j]).    i-j+1<=n


=s[i-1]+f[i]+(f[j]-s[j]).    i-j+1<=n
=s[i-1]+f[i]+max(p[i]).    i-j+1<=n
p[i]=f[i]-s[i]

*/