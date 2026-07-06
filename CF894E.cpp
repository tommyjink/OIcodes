#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,s,dfn[N],low[N],num=0,cnt=0,val[N];
int head[N],tot=0,in[N],col[N],c[N],ans=0,dp[N];
stack<int> st;
vector<pii> edge[N];
struct node
{
    int from,to,next,val;
}e[N*2];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    in[x]=true,st.push(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(in[v])low[x]=min(dfn[v],low[x]);
    }
    if(low[x]==dfn[x])
    {
        cnt++;
        while(!st.empty())
        {
            int t=st.top();st.pop();
            in[t]=false,col[t]=cnt;
            c[cnt]++;
            if(t==x)break;
        }
    }
}
int dfs(int x)
{
    if(dp[x])return dp[x];
    dp[x]=val[x];
    for(pii v:edge[x])
        dp[x]=max(dp[x],val[x]+v.second+dfs(v.first));
    return dp[x];
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        add(x,y,z);
    }
    cin>>s;
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=tot;i++)
    {
        int x=e[i].from,y=e[i].to;
        if(col[x]==col[y])
        {
            //1+2+3+4+......+f=(1+f)*f/2
            //n=(1+f)*f/2
            //2*n=f*(f+1)
            int f=sqrt(e[i].val*2);
            if(f*(f+1)/2>e[i].val)f--;
            if(e[i].val==3)f=2;
            //n+(n-1)+(n-1-2)+(n-1-2-3)+......+(n-(1+f)*f/2)
            //n*(f+1)-1*f-2*(f-1)-3*(f-2)-4*(f-3)-......-f*(f-(f-1))
            //n*(f+1)-(1+2+3+4+5+6+...+f)*f+2*1+3*2+4*3+....+f*(f-1)
            //n*(f+1)-(1+f)*f*f/2+(f-1)*f*(f+1)/3
            val[col[x]]+=e[i].val*(f+1)-(1+f)*f*f/2+(f-1)*f*(f+1)/3;
        }
        else edge[col[x]].push_back(make_pair(col[y],e[i].val));
    }
    cout<<dfs(col[s])<<endl;
    return 0;
}