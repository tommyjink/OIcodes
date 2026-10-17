#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,q,dp[N][4],a[N],b[N],c[N];
int head[N],tot,rt,dep[N],g[N],fa[N],st[N],top;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int f)
{
    st[++top]=x;
    fa[x]=f;
    dep[x]=dep[f]+1;
    for(int j=1;j<=top;j++)
    {
        x=st[j];
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(v==fa[x])continue;
            fa[v]=x;
            dep[v]=dep[x]+1;
            st[++top]=v;
        }
    }
    for(int j=top;j>=1;j--)
    {
        x=st[j];
        int cnt=0,res=0,sum=0,mx=0;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(fa[v]!=x)continue;
            res+=dp[v][0];
            sum+=dp[v][1];
            if(!cnt)mx=dp[v][2]-dp[v][0];
            else mx=max(mx,dp[v][2]-dp[v][0]);
            cnt++;
        }
        dp[x][2]=sum;
        dp[x][0]=max(dp[x][2],a[x]+res);
        if(cnt)dp[x][0]=max(dp[x][0],b[x]+res+mx);
        dp[x][1]=max({dp[x][2],a[x]+res,b[x]+res});
        dp[x][3]=max(dp[x][2],max(a[x],b[x])+res);
        g[dep[x]]+=dp[x][3];
        c[dep[x]]+=max(a[x],b[x]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    cin>>rt;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(rt,rt);
    for(int i=1;i<=n;i++)c[i]+=c[i-1];
    while(q--)
    {
        int L;cin>>L;
        L=min(L,n);
        cout<<c[L]+g[L+1]<<endl;
    }
    return 0;
}
