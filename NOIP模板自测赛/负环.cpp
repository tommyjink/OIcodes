#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,head[N],tot=0,dis[N],vis[N];
int cnt[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
bool SPFA()
{
    for(int i=1;i<=n;i++)
        dis[i]=INF,vis[i]=false;
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty())
    {
        int t=q.front();q.pop();
        vis[t]=false;
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to,w=e[i].val;
            if(dis[t]+w<dis[v])
            {
                dis[v]=dis[t]+w;
                if(!vis[v])
                {
                    if(++cnt[v]>n)return false;
                    q.push(v),vis[v]=true;
                }
            }
        }
    }
    return true;
    
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        head[i]=cnt[i]=0;
    tot=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        if(z>=0)add(y,x,z);
    }
    if(!SPFA())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}