#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=510,K=12,INF=1e18;
int n,m,k,dis[N][N][K];
char a[N][N];
struct node
{
    int x,y,z;
};
signed main()
{
    freopen("maze.in","r",stdin);freopen("maze.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m>>k;
    int sx=0,sy=0,tx=0,ty=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='S')sx=i,sy=j;
            if(a[i][j]=='T')tx=i,ty=j;
        }
    memset(dis,-1,sizeof(dis));queue<node> q;
    dis[sx][sy][0]=0;q.push((node){sx,sy,0});
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    while(q.size())
    {
        node u=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x<1||x>n||y<1||y>m)continue;
            int z=u.z+(a[x][y]=='#');
            if(z>k||dis[x][y][z]!=-1)continue;
            dis[x][y][z]=dis[u.x][u.y][u.z]+1;
            q.push((node){x,y,z});
        }
    }
    int ans=INF;
    for(int i=0;i<=k;i++)if(dis[tx][ty][i]!=-1)ans=min(ans,dis[tx][ty][i]);
    cout<<(ans==INF?-1:ans)<<endl;
    return 0;
}
