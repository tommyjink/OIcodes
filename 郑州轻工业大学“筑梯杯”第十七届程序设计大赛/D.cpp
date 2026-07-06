#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m,col[N][N],mp[N][N],cc=0;
void dfs(int num,int x,int y)
{
    col[x][y]=num;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||yy<1||xx>n||yy>m||mp[xx][yy]||col[xx][yy])
            continue;
        dfs(num,xx,yy);
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
            if(s[j-1]=='#')
                mp[i][j]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!(col[i][j]||mp[i][j]))
                dfs(++cc,i,j);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout<<col[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int q;cin>>q;
    while(q--)
    {
        int x,y,xx,yy,xxx,yyy;
        cin>>x>>y>>xx>>yy>>xxx>>yyy;
        if(!(col[x][y]==col[xx][yy]&&col[xx][yy]==col[xxx][yyy]))
        {
            cout<<"No"<<endl;
            continue;
        }
        int dis1=abs(x-xxx)+abs(y-yyy)+1;
        int dis2=abs(xx-xxx)+abs(yy-yyy)+1;
        int tag1=0,tag2=0,t1=0,t2=0;
        for(int i=0;i<4;i++)
        {
            int tx=x+dx[i],ty=y+dy[i];
            if(tx==xxx&&ty==yyy)t1=true;
            if(tx<1||ty<1||tx>n||ty>m||(tx==xxx&&ty==yyy)||mp[tx][ty])
                continue;
            tag1=true;
        }
        for(int i=0;i<4;i++)
        {
            int tx=xx+dx[i],ty=yy+dy[i];
            if(tx==xxx&&ty==yyy)t2=true;
            if(tx<1||ty<1||tx>n||ty>m||(tx==xxx&&ty==yyy)||mp[tx][ty])
                continue;
            tag2=true;
        }
        if(tag1==tag2&&tag1==false)
            cout<<"Yes"<<endl;
        else if(tag1==tag2&&tag1==true&&(dis1+dis2)%2==0)
            cout<<"Yes"<<endl;
        else if(t1==t2&&t1==true)
            cout<<"Yes"<<endl;
        else if((tag1==false&&t2)||(tag2==false&&t1))
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}