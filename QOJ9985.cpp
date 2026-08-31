#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,k,head[N],tot,tag[N];
int vis[N],rk[N],cnt,tt[N],num;
vector<pii> E;
vector<int> b[N];
vector<int> id[N];
struct node
{
    int to,next;
}e[N*4];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
bool bfs()
{
    queue<int> q;
    vector<int> g,gg;
    int now=0;
    if(tag[1])
    {
        g.push_back(1);
        now^=1;
        vis[1]=1;
    }
    else q.push(1),vis[1]=1;
    while(1)
    {
        while(!q.empty())
        {
            int t=q.front();q.pop();
            vis[t]=true;
            rk[t]=++cnt;
            for(int i=head[t];i;i=e[i].next)
            {
                int v=e[i].to;
                if(vis[v])continue;
                vis[v]=true;
                if(tag[v])
                {
                    g.push_back(v);
                    now^=v;
                }
                else q.push(v);
            }
        }
        if(num==k)return cnt==n;
        sort(g.begin(),g.end());
        gg.clear();
        int bb=0;
        for(int i:id[now])
        {
            if(tt[i])continue;
            if(g==b[i])
            {
                tt[i]=bb=1;
                for(int j:b[i])
                    if(!--tag[j])
                        q.push(j),now^=j;
                    else gg.push_back(j);
                break;
            }
        }
        if(!bb)return false;
        else num++;
        g=gg;
    }
    return true;
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<=2*n;i++)
    {
        head[i]=tag[i]=vis[i]=tt[i]=0;
        id[i].clear();
    }
    E.clear();
    tot=cnt=num=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        E.push_back({x,y});
        add(x,y);
        add(y,x);
    }
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        b[i].clear();
        int o;cin>>o;
        int res=0;
        for(int j=1;j<=o;j++)
        {
            int x;cin>>x;
            tag[x]++;
            b[i].push_back(x);
            res^=x;
        }
        id[res].push_back(i);
        sort(b[i].begin(),b[i].end());
    }
    if(bfs())
    {
        cout<<"Yes"<<endl;
        for(int i=1;i<=m;i++)
            cout<<abs(rk[E[i-1].first]-rk[E[i-1].second])<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}