#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,head[N],dis[N],tot=0,vis[N],cnt[N];
int in[N];
struct node
{
    int to,next,val;
}e[N*4];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
bool SPFA()
{
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i),dis[i]=0;
    if(q.empty())q.push(1),dis[1]=0;
    while(!q.empty())
    {
        int t=q.front();q.pop();
        // cout<<t<<endl;
        vis[t]=false;
        // cout<<head[t]<<endl;
        for(int i=head[t];i;i=e[i].next)
        {
            // cout<<"!"<<endl;
            int v=e[i].to,w=e[i].val;
            if(dis[t]+w<dis[v])
            {
                dis[v]=dis[t]+w;
                if(!vis[v])
                {
                    vis[v]=true;
                    if(++cnt[v]>n)return false;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(y,x,z);
        in[x]++;
    }
    if(SPFA())
    {
        for(int i=1;i<=n;i++)
            cout<<dis[i]<<" ";
        cout<<endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}