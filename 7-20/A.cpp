#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5005;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
const int ddx[]={1,1,-1,-1},ddy[]={-1,1,-1,1};
int n,m,mp[N][N],sx,sy,tx,ty,done[N][N],cnt=0;
pii dis[N][N];
struct Point
{
    int x,y,dis1,dis2;
};
bool operator <(Point x,Point y)
{
    return x.dis1==y.dis1?x.dis2>y.dis2:x.dis1>y.dis1;
}
priority_queue<Point> q;
void dijkstra()
{
    memset(dis,63,sizeof(dis));
    dis[sx][sy]=pii(0,0);
    q.push(Point{sx,sy,0,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.x][t.y])continue;
        done[t.x][t.y]=true;
        for(int i=0;i<4;i++)
        {
            int xx=t.x+ddx[i],yy=t.y+ddy[i];
            if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]||done[xx][yy])continue;
            if(pii(t.dis1,t.dis2+1)<dis[xx][yy])
            {
                dis[xx][yy]=pii(t.dis1,t.dis2+1);
                q.push(Point{xx,yy,t.dis1,t.dis2+1});
            }
        }
        for(int i=0;i<4;i++)
        {
            int xx=t.x+dx[i],yy=t.y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]||done[xx][yy])continue;
            if(pii(t.dis1+1,t.dis2)<dis[xx][yy])
            {
                dis[xx][yy]=pii(t.dis1+1,t.dis2);
                q.push(Point{xx,yy,t.dis1+1,t.dis2});
            }
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
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='X')
                sx=i,sy=j;
            else if(s[j-1]=='W')
                tx=i,ty=j;
            else if(s[j-1]=='#')
                mp[i][j]=true,cnt++;
            else mp[i][j]=false;
        }
    }
    if(cnt==0&&n*m>1e6)
    {
        int X=abs(sx-tx),Y=abs(sy-ty);
        if(n==1)cout<<Y<<" 0"<<endl;
        else if(m==1)cout<<X<<" 0"<<endl;
        else if((X+Y)%2)cout<<(X+Y)%2<<" "<<max(X,Y)-1<<endl;
        else cout<<(X+Y)%2<<" "<<max(X,Y)<<endl;
        return 0;
    }
    dijkstra();
    if(dis[tx][ty].first>1e9)cout<<"-1 -1"<<endl;
    else cout<<dis[tx][ty].first<<" "<<dis[tx][ty].second<<endl;
    return 0;
}