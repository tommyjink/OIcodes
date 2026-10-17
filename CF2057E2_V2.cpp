#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int N=500,INF=1e9;
int n,m,q,fa[N];
int dis[N][N][N],val[N];
struct node
{
    int x,y,z;
}e[N*N];
bool cmp(node a,node y)
{
    return a.z<y.z;
}
int getfa(int x)
{
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
bool merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return false;
    fa[x]=y;
    return true;
}
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)dis[0][i][j]=INF;
    for(int i=1;i<=n;i++)dis[0][i][i]=0;
    for(int i=1;i<=m;i++)dis[0][e[i].y][e[i].x]=dis[0][e[i].x][e[i].y]=1;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[0][i][j]=min(dis[0][i][j],dis[0][i][k]+dis[0][k][j]);
    int now=0;
    for(int i=1;i<=m;i++)
    {
        int x=e[i].x,y=e[i].y;
        if(merge(x,y))
        {
            now++;
            val[now]=e[i].z;
            for(int u=1;u<=n;u++)
                for(int v=1;v<=n;v++)
                    dis[now][u][v]=min({dis[now-1][u][v],dis[now-1][u][x]+dis[now-1][y][v],dis[now-1][v][x]+dis[now-1][y][u]});
        }
    }
    while(q--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(dis[mid][a][b]<k)r=mid;
            else l=mid+1;
        }
        cout<<val[l]<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}