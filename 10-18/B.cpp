#include<bits/stdc++.h>
#define int long long
#define c(x,y) (m+2)*(x)+y+1
#define endl "\n"
using namespace std;
const int N=1e6+10;
const int dx[8]={0,0,-1,1,1,1,-1,-1};
const int dy[8]={1,-1,0,0,1,-1,1,-1};
int mp[N],n,m,col[N],vis[N];
void dfs(int x,int y,int C)
{
    col[c(x,y)]=C;
    vis[c(x,y)]=1;
    for(int i=0;i<8;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0||yy<0||xx>n+1||yy>m+1)continue;
        col[c(xx,yy)]=C;
    }
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0||yy<0||xx>n+1||yy>m+1)continue;
        if(vis[c(xx,yy)]||!mp[c(xx,yy)])continue;
        dfs(xx,yy,C);
    }
}
bool dfs2(int x,int y,int C)
{
    if((x+1==n&&y==m)||(x==n&&y+1==m))
        return true;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||yy<1||xx>n||yy>m)continue;
        if(mp[c(xx,yy)]||vis[c(xx,yy)])continue;
        if(col[c(xx,yy)]!=C)continue;
        vis[c(xx,yy)]=true;
        if(dfs2(xx,yy,C))return true;
        vis[c(xx,yy)]=false;
    }  
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||yy<1||xx>n||yy>m)continue;
        if(mp[c(xx,yy)]||vis[c(xx,yy)])continue;
        if(col[c(xx,yy)])continue;
        vis[c(xx,yy)]=true;
        if(dfs2(xx,yy,C))return true;
        vis[c(xx,yy)]=false;
    }  
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            mp[c(i,j)]=1;
    mp[c(0,0)]=mp[c(n+1,m+1)]=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='#') mp[c(i,j)]=1;
            else mp[c(i,j)]=0;
        }
    }
    dfs(1,0,1);
    dfs(0,1,2);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //         if(mp[c(i,j)])
    //             cout<<"# ";
    //         else cout<<col[c(i,j)]<<" ";
    //     cout<<endl;
    // }
    memset(vis,0,sizeof(vis));
    if(!dfs2(1,1,1))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(vis[c(i,j)])
                mp[c(i,j)]=2;
    
    memset(vis,0,sizeof(vis));
    if(!dfs2(1,1,2))
    {
        cout<<"NO"<<endl;
        return 0;
    }
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


2 2
.#
..
NO
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
4 7
.....##
..#....
..##...
.......
YES
.VVVV##
KK#.VVV
.K##..V
.KKKKK.


16 14
..............
..............
############..
...........#..
...........#..
..#######..#..
..#.....#..#..
..#.....#..#..
..#..#.....#..
..#..#.....#..
..#..#######..
..#...........
..#...........
..############
..............
..............
YES
.VVVVVVVVVVVVV
KKKKKKKKKKKKKV
############KV
KKKKKKKKKKK#KV
KVVVVVVVVVK#KV
KV#######VK#KV
KV#VVVVV#VK#KV
KV#VKKKV#VK#KV
KV#VK#KVVVK#KV
KV#VK#KKKKK#KV
KV#VK#######KV
KV#VKKKKKKKKKV
KV#VVVVVVVVVVV
KV############
KVVVVVVVVVVVVV
KKKKKKKKKKKKK.

*/