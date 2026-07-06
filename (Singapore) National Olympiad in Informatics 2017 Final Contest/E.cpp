#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,q,l[N],p[N],vis[N],cnt[N];
inline int f(int x,int y)
{
    return (x-1)*m+y;
}
int dfs(int x,int y,int level)
{
    // cout<<x<<","<<y<<endl;
    if(l[f(x,y)]>level)return 0;
    int res=0;
    if(++cnt[p[f(x,y)]]==1)res++;
    vis[f(x,y)]=true;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||yy<1||xx>n||yy>m||vis[f(xx,yy)])continue;
        res+=dfs(xx,yy,level);
    }
    return res;
}
void dfs1(int x,int y)
{
    cnt[p[f(x,y)]]=0;
    vis[f(x,y)]=false;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||yy<1||xx>n||yy>m||!vis[f(xx,yy)])continue;
        dfs1(xx,yy);
    }   
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>l[f(i,j)];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[f(i,j)];
    while(q--)
    {
        int op,x,y,z;
        cin>>op>>y>>x>>z;
        if(op==1) p[f(x,y)]=z;
        else
        {
            cout<<dfs(x,y,z)<<endl;
            dfs1(x,y);
        }
    }
    return 0;
}