#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e16;
int n,m,S,s,t,dis[N],now[N],limit;
int tot,head[N],ban[N],tag[N];
struct node
{
    int to,next,val;
}e[N*30];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z},head[x]=tot;
    e[++tot]=(node){x,head[y],0},head[y]=tot;
}
queue<int> q;
bool bfs()
{
    for(int i=0;i<=t;i++)
        dis[i]=INF,now[i]=head[i];
    while(!q.empty())q.pop();
    q.push(s),dis[s]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].val&&dis[v]==INF)dis[v]=dis[x]+1,q.push(v);
        }
    }
    return dis[t]!=INF;
}
int dfs(int x,int sum)
{
    int res=0;
    if(x==t||!sum)return sum;
    for(int i=now[x];i&&sum>0;i=e[i].next)
    {
        now[x]=i;
        int v=e[i].to;
        if(!e[i].val||dis[x]+1!=dis[v])continue;
        int k=dfs(v,min(sum,e[i].val));
        if(!k)dis[v]=INF;
        e[i].val-=k,e[i^1].val+=k;
        sum-=k,res+=k;
    }
    return res;
}
int F(int *c)
{
    int res=0;
    for(int i=m;i>=1;i--)
        res=res*10+c[i];
    return res;
}
void solve()
{
    cin>>m>>n>>S;
    limit=1;
    for(int i=1;i<=m;i++)limit*=10;
    s=limit,t=s+1,tot=1;
    for(int i=0;i<=t;i++)
        head[i]=ban[i]=tag[i]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ban[x]=1;
    }
    if(ban[S])
    {
        cout<<"Bob"<<endl;
        return;
    }
    queue<int> Q;
    Q.push(S);
    tag[S]=1;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        int c[10]={0},xx=u;
        for(int i=1;i<=m;i++)
            c[i]=xx%10,xx/=10;
        for(int i=1;i<=m;i++)
        {
            int cc=c[i];
            c[i]=(cc+1)%10;
            int v1=F(c);
            c[i]=(cc+9)%10;
            int v2=F(c);
            c[i]=cc;
            int nxt[2]={v1,v2};
            for(int j=0;j<2;j++)
            {
                int v=nxt[j];
                if(ban[v])continue;
                if(!tag[v])
                {
                    tag[v]=3-tag[u];
                    Q.push(v);
                }
                if(tag[u]==1)add(u,v,1);
            }
        }
    }
    for(int i=0;i<limit;i++)
    {
        if(!tag[i]||i==S)continue;
        if(tag[i]==1)add(s,i,1);
        else add(i,t,1);
    }
    while(bfs())dfs(s,INF);
    if(tag[S]==1)add(s,S,1);
    else add(S,t,1);
    if(bfs()&&dfs(s,INF))cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}