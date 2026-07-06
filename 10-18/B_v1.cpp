#include<bits/stdc++.h>
#define int long long
#define c(x,y) (m)*(x-1)+y
#define endl "\n"
using namespace std;
const int N=1e6+10;
const int dx[2][4]={{1,0,-1,0},{0,-1,0,1}};
const int dy[2][4]={{0,-1,0,1},{1,0,-1,0}};
int mp[N],n,m,vis[N];
bool dfs(int x,int y,int M,int num)
{
    cout<<x<<","<<y<<endl;
    if(x==n&&y==m)return true;
    for(int i=num+1;i>=num;i--)
    {
        int xx=x+dx[M][i%4];
        int yy=y+dy[M][i%4];
        if(xx<1||yy<1||xx>n||yy>m)
            continue;
        if(mp[c(xx,yy)]||vis[c(xx,yy)])
            continue;
        vis[c(xx,yy)]=true;
        if(dfs(xx,yy,M,i%4))return true;
        vis[c(xx,yy)]=false;
    }
    return false;
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
            if(s[j-1]=='#')
                mp[c(i,j)]=1;
    }
    if(!dfs(1,1,0,0))
    {
        cout<<"NO"<<endl;
        // return 0;
    }
    vis[c(n,m)]=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(vis[c(i,j)])
                mp[c(i,j)]=2;
    memset(vis,0,sizeof(vis));
    if(!dfs(1,1,1,0))
    {
        cout<<"NO"<<endl;
        // return 0;
    }
    vis[c(n,m)]=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(vis[c(i,j)])
                mp[c(i,j)]=3;
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[c(i,j)]==0)cout<<".";
            if(mp[c(i,j)]==1)cout<<"#";
            if(mp[c(i,j)]==2)cout<<"K";
            if(mp[c(i,j)]==3)cout<<"V";
        }
        cout<<endl;
    }
    return 0;
}
/*
3 3
...
.#.
...


YES
.VV
K#V
KK.





10 10
........##
..##.##.##
#....##...
###....##.
###.##.#..
#......###
#.###..###
#...#.....
#.#.#.....
########..


YES
.VVVV...##
KK##V##.##
#KKKV##...
###KVVV##.
###K##V#..
#..KKKV###
#.###KV###
#...#KVVVV
#.#.#KKKKV
########K.

YES
.VVVV...##
KK##V##.##
#KKKV##...
###KVVV##.
###K##V#..
#..KKKV###
#.###KV###
#...#KVVVV
#.#.#KKKKV
########K.
*/