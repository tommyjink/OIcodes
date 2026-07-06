#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int mp[1000][1000];
int main()
{
    int n,m,cnt,now=0,ans=0,x=1,y=1;
    mp[1][1]=1;
    cin>>n>>m;
    cnt=n*m-1;
    while(cnt)
    {
        while(1)
        {
            int xx=x+dx[now],yy=y+dy[now];
            if(xx<1||yy<1||xx>n||yy>m||mp[xx][yy]==1)break;
            x=xx,y=yy,cnt--,mp[xx][yy]=1;
            // for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<mp[i][j];cout<<endl;}
            // cout<<ans<<endl;
        }
        ans++,now=(now+1)%4;
    }
    cout<<ans-1;
    return 0;
}