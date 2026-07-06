#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=100;
const int dx[]={0,-1,0,1};
const int dy[]={-1,0,1,0};
int n,m,p[N][N][4],col[N][N],num=0,cnt[N*N],maxcnt=0;
void dfs(int x,int y)
{
    col[x][y]=num;
    cnt[num]++;
    maxcnt=max(maxcnt,cnt[num]);
    for(int i=0;i<=3;i++)
    {
        if(p[x][y][i])continue;
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(col[xx][yy])continue;
        dfs(xx,yy);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int v;cin>>v;
            for(int k=0;k<=3;k++)
                p[i][j][k]=(v&(1ll<<k));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!col[i][j])++num,dfs(i,j);
    cout<<num<<endl;
    cout<<maxcnt<<endl;
    pii ans1,ans2;
    int val1=-1,val2=-1;
    for(int j=1;j<=m;j++)
    {
        for(int i=n;i>=2;i--)
        {
            if(p[i][j][1])
            {
                if(col[i][j]==col[i-1][j]&&cnt[col[i][j]]>val1)
                    ans1=pii(i,j),val1=cnt[col[i][j]];
                else if(col[i][j]!=col[i-1][j]&&cnt[col[i][j]]+cnt[col[i-1][j]]>val1)
                    ans1=pii(i,j),val1=cnt[col[i][j]]+cnt[col[i-1][j]];
            }
        }
    }
    for(int j=1;j<=m-1;j++)
    {
        for(int i=n;i>=1;i--)
        {
            if(p[i][j][2])
            {
                if(col[i][j]==col[i][j+1]&&cnt[col[i][j]]>val2)
                    ans2=pii(i,j),val2=cnt[col[i][j]];
                else if(col[i][j]!=col[i][j+1]&&cnt[col[i][j]]+cnt[col[i][j+1]]>val2)
                    ans2=pii(i,j),val2=cnt[col[i][j]]+cnt[col[i][j+1]];
            }
        }
    }
    cout<<max(val2,val1)<<endl;
    if(val1>val2)cout<<ans1.first<<" "<<ans1.second<<" N"<<endl;
    else if(val2>val1)cout<<ans2.first<<" "<<ans2.second<<" E"<<endl;
    else
    {
        if(ans1.second<ans2.second)cout<<ans1.first<<" "<<ans1.second<<" N"<<endl;
        else if(ans1.second>ans2.second)cout<<ans2.first<<" "<<ans2.second<<" E"<<endl;
        else if(ans1.first>=ans2.first)cout<<ans1.first<<" "<<ans1.second<<" N"<<endl;
        else cout<<ans2.first<<" "<<ans2.second<<" E"<<endl;
    }
    return 0;
}