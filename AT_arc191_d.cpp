#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,s,t,tot=0,head[N],D;
int dis1[N],dis2[N],in[N],dis3[N];
vector<int> V[N];
struct node
{
    int to,next,from,ban;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x,0};
    head[x]=tot;
}
void bfs(int s,int *dis)
{
    queue<int> q;
    q.push(s);
    dis[s]=0;
    for(int i=1;i<=n;i++)
        dis[i]=-1;
    dis[s]=0;
    while(!q.empty())
    {
        int t=q.front();q.pop();
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(~dis[v]||e[i].ban)continue;
            dis[v]=dis[t]+1;
            q.push(v);
        }
    }
}
bool check(int x)
{
    return dis1[x]+dis2[x]==D;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        in[x]++,in[y]++;
    }
    bfs(s,dis1);
    bfs(t,dis2);
    D=dis1[t];
    if(D==-1||D==m)cout<<"-1",exit(0);
    for(int i=1;i<=n;i++)
    {
        if(dis1[i]+dis2[i]==D)
            V[dis1[i]].push_back(i);
    }
    for(int i=1;i<=D;i++)
        if(V[i].size()>1)cout<<2*D,exit(0);
    int tag=0;
    for(int i=1;i<=D-1;i++)
        for(int j:V[i])if(in[j]!=2)tag=1;
    for(int i=1;i<=tot;i++)
        if(check(e[i].to)&&check(e[i].from))
            e[i].ban=1;
    bfs(s,dis3);
    int ans=1e18;
    for(int i=1;i<=n;i++)
        if(dis1[i]&&dis2[i]&&dis1[i]+dis2[i]==D+1)
            ans=min(ans,2*D+1);
    if(tag)ans=min(ans,2*D+2);
    if(dis3[t]!=-1)ans=min(ans,dis3[t]+D);
    for(int i=1;i<=n;i++)
        if(in[i]>=3)
            ans=min(ans,2*D+4+4*min(dis1[i],dis2[i]));
    if(ans>1e9)cout<<"-1";
    else cout<<ans;

    return 0;
}