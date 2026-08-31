#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=70;
int n,m,sx,sy,tx,ty,tot,fl;
int vis[N][N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char ch[4]={'R','D','L','U'};
char ans[N*N];

int get(int x,int y)
{
    int res=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>m||vis[xx][yy])continue;
        res++;
    }
    return res;
}

void dfs(int x,int y,int dep)
{
    if(fl)return;
    int rem=tot-dep;
    int dis=abs(x-tx)+abs(y-ty);
    if(dis>rem||((rem-dis)&1))return;
    if(x==tx&&y==ty&&dep<tot)return;
    if(dep==tot)
    {
        if(x==tx&&y==ty)
        {
            fl=true;
            ans[dep]=0;
        }
        return;
    }
    int q[5],d[5],cnt=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>m||vis[xx][yy])continue;
        q[++cnt]=i;
        d[cnt]=get(xx,yy);
    }
    for(int i=1;i<=cnt;i++)
        for(int j=i+1;j<=cnt;j++)
            if(d[j]<d[i])
            {
                swap(d[i],d[j]);
                swap(q[i],q[j]);
            }
    for(int i=1;i<=cnt;i++)
    {
        int id=q[i];
        int xx=x+dx[id],yy=y+dy[id];
        vis[xx][yy]=1;
        ans[dep]=ch[id];
        dfs(xx,yy,dep+1);
        if(fl)return;
        vis[xx][yy]=0;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>sx>>sy>>tx>>ty;
    tot=n*m-1;
    if(n*m>64)
    {
        cout<<endl;
        return 0;
    }
    vis[sx][sy]=1;
    dfs(sx,sy,0);
    if(fl)cout<<ans<<endl;
    else cout<<endl;
    return 0;
}
