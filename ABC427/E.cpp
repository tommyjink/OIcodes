#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20;
const int dx[]={1,1,-1,-1};
const int dy[]={-1,1,-1,1};
int n,m,mp[N][N],sx,sy,vis[N][N],dis[N][N];
int xmin[N],ymin[N];
struct node
{
    int x,y,dis;
};
void bfs()
{
    memset(dis,127,sizeof(dis));
    queue<node> q;
    q.push((node){sx,sy,0});
    while(!q.empty())
    {
        node t=q.front();q.pop();
        if(vis[t.x][t.y])continue;
        vis[t.x][t.y]=1;
        dis[t.x][t.y]=t.dis;
        for(int i=0;i<4;i++)
        {
            int xx=t.x+dx[i];
            int yy=t.y+dy[i];
            if(xx<1||yy<1||xx>n||yy>m||mp[xx][yy]||vis[xx][yy])continue;
            q.push((node){xx,yy,t.dis+1});
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
        {
            if(s[j-1]=='#')mp[i][j]=1;
            else mp[i][j]=0;
            if(s[j-1]=='T')sx=i,sy=j;
        }
    }
    bfs();
    memset(xmin,63,sizeof(xmin));
    memset(ymin,63,sizeof(ymin));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            xmin[i]=min(xmin[i],dis[i][j]);
            ymin[j]=min(ymin[j],dis[i][j]);
        }
    }
    int ans=1e15;
    for(int i=1;i<=sx;i++)
        ans=min(ans,xmin[i]*2+xmin[n-(sx-i)]+(sx-i));
    for(int i=sx;i<=n;i++)
        ans=min(ans,xmin[i]*2+xmin[1+i-sx]+i-sx);
    for(int i=1;i<=sy;i++)
        ans=min(ans,ymin[i]*2+ymin[m-(sy-i)]+(sy-i));
    for(int i=sy;i<=n;i++)
        ans=min(ans,ymin[i]*2+ymin[1+i-sy]+i-sy);
    if(ans<1e9)
        cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}