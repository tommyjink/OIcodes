#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,INF=1e16;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int n,m,g,dis[N],b[N];
int tot,head[N],p[N];
int dfn[N],low[N],num;
int stk[N],top=0,col[N],cnt;
int siz[N],tag[N],l[N];
vector<int> r[N];
vector<int> V[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
int cal(int x,int y)
{
    return (x-1)*m+y;
}
pii fcal(int x)
{
    if(x==1)return {1,1};
    return {(x-1)/m+1,x-m*((x-1)/m)};
}
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stk[top++]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        while(1)
        {
            int t=stk[--top];
            col[t]=cnt;
            l[cnt]=t;
            siz[cnt]++;
            if(t==x)break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>g;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            int k=0;
            if(s[j-1]=='N'||s[j-1]=='n')k=0;
            if(s[j-1]=='S'||s[j-1]=='s')k=1;
            if(s[j-1]=='W'||s[j-1]=='w')k=2;
            if(s[j-1]=='E'||s[j-1]=='e')k=3;
            int x=cal(i,j),y=cal(i+dx[k],j+dy[k]);
            if(s[j-1]>='A'&&s[j-1]<='Z')tag[x]=1;
            add(x,y);
            r[y].push_back(x);
        }   
    }
    for(int i=1;i<=n*m;i++)
        if(!dfn[i])tarjan(i);
    queue<pii> q;
    for(int i=1;i<=n*m;i++)
        dis[i]=INF;
    for(int i=1;i<=cnt;i++)
        if(siz[i]>1)q.push({l[i],i}),dis[l[i]]=1;
    while(!q.empty())
    {
        int x=q.front().first,c=q.front().second;q.pop();
        if(tag[x])V[c].push_back(x);
        // cout<<fcal(x).first<<" "<<fcal(x).second<<endl;
        for(int v:r[x])
        {
            if(dis[v]!=INF)continue;
            dis[v]=dis[x]+1;
            q.push({v,c});
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //         cout<<dis[cal(i,j)]<<" ";
    //     cout<<endl;
    // }
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        if(siz[i]<=1)continue;
        p[i]=min((int)V[i].size(),siz[i]);
        ans+=p[i];
        for(int j=0;j<p[i];j++)
        {
            int v=V[i][j];
            b[v]=1e8-j-dis[v];
        }
    }
    cout<<ans<<endl;
    if(!g)return 0;
    for(int i=1;i<=cnt;i++)
    {
        if(siz[i]<=1)continue;
        for(int j=0;j<p[i];j++)
            cout<<fcal(V[i][j]).first<<" "<<fcal(V[i][j]).second<<" "<<b[V[i][j]]<<endl;
    }
    return 0;
}