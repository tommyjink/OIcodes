#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3,dx[]={0,0,1,-1},dy[]={1,-1,0,0},M=11,L=500;
int vis[N][N],vis2[N][N],ans=0;
void dfs(int x,int y,bool mode,int cnt)
{
    if(cnt>M)
    {
        vis[x][y]=1;
        return;
    }
    int l,r;
    if(mode)l=0,r=1;
    else l=2,r=3;
    for(int i=l;i<=r;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        dfs(xx,yy,mode^1,cnt+1);
    }
}
void dfs1(int x,int y,bool mode,int cnt)
{
    if(cnt>M)
    {
        vis2[x][y]=1;
        return;
    }
    int l,r;
    if(mode)l=0,r=1;
    else l=2,r=3;
    for(int i=l;i<=r;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        dfs1(xx,yy,mode^1,cnt+1);
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dfs(500,500,1,1);
    dfs1(500,500,0,1);
    for(int i=L-10;i<=L+10;i++)
    {
        for(int j=L-10;j<=L+10;j++)
        {
            cout<<(vis[i][j]|vis2[i][j])<<" ";
            if(vis[i][j]|vis2[i][j])ans++;
        }
        cout<<endl;
    }
    cout<<ans;
    return 0;
}