#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+100;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,m,sx,sy,tx,ty,px,py,a[N][N],vis[N][N];
int sav[N][N],tag[N][N],dis[N][N];
struct point
{
    int x,y,s,step;
};
void bfs(int sx,int sy)
{
    queue<point> q;
    q.push((point){sx,sy,4,0});
    memset(vis,0,sizeof(vis));
    memset(dis,127,sizeof(dis));
    while(!q.empty())
    {
        point t=q.front();q.pop();
        if(vis[t.x][t.y])continue;
        vis[t.x][t.y]=true;
        sav[t.x][t.y]=t.s;
        dis[t.x][t.y]=t.step;
        for(int i=0;i<4;i++)
        {
            int xx=t.x+dx[i];
            int yy=t.y+dy[i];
            if(xx<1||yy<1||xx>n||yy>m||vis[xx][yy]||a[xx][yy])continue;
            q.push((point){xx,yy,i,t.step+1});
        }
    }
}
signed main()
{
    freopen("safe.in","r",stdin);
    freopen("safe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>sx>>sy>>tx>>ty>>px>>py;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    bfs(sx,sy);
    int xx=px,yy=py;
    while(1)
    {
        if(xx<1||yy<1||xx>n||yy>m||a[xx][yy])
        {
            cout<<"-1";
            return 0;
        }
        tag[xx][yy]=true;
        if(sav[xx][yy]>=4)break;
        int txx=xx-dx[sav[xx][yy]];
        int tyy=yy-dy[sav[xx][yy]];
        xx=txx;
        yy=tyy;
    }
    bfs(tx,ty);
    int ans=1e9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(tag[i][j])
                ans=min(ans,dis[i][j]);
    cout<<(ans<1e9?ans:-1)<<endl;
    return 0;
}