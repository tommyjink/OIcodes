#include<bits/stdc++.h>

#define int long long
#define endl "\n"
using namespace std;
int n,a[10][10],done=false;
int ans[10][3];
bool check()
{
    for(int i=1;i<=5;i++)
        if(a[i][1])return false;
    return true;
}
bool fall()
{
    bool tag=false;
    for(int i=1;i<=5;i++)
        for(int j=7;j>=1;j--)
            if(a[i][j]&&!a[i][j-1])
                swap(a[i][j],a[i][j-1]),tag=true;
    return tag;
}
bool del()
{
    int tag1[10][10],tag2[10][10],tag=0;
    memset(tag1,0,sizeof(tag1));
    memset(tag2,0,sizeof(tag2));
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
        {
            if(a[i][j]&&a[i][j]==a[i][j-1]&&a[i][j]==a[i][j+1]) tag1[i][j]=true;
            if(a[i][j]&&a[i-1][j]==a[i][j]&&a[i+1][j]==a[i][j]) tag2[i][j]=true;
        }
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
        {
            if(tag1[i][j]) a[i][j]=a[i][j-1]=a[i][j+1]=0,tag=true;
            if(tag2[i][j]) a[i][j]=a[i-1][j]=a[i+1][j]=0,tag=true;
        }
    return tag;
}
void mov(int x,int y,int mode)
{
    int xx=x+mode,yy=y;
    swap(a[xx][yy],a[x][y]);
    while(1)
    {
        while(fall());
        if(!del())return;
    }
}
void copy(int b[10][10])
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
            b[i][j]=a[i][j];
}
void rback(int b[10][10])
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
            a[i][j]=b[i][j];
}
void print()
{
    for(int j=7;j>=1;j--)
    {
        for(int i=1;i<=5;i++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void dfs(int k)
{
    // cout<<k<<":______"<<endl;
    // print();
    // getchar();
    if(k==n+1)
    {
        if(check()) done=true;
        return;
    }
    int b[10][10];
    copy(b);
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(!a[i][j])break;
            ans[k][0]=i,ans[k][1]=j;
            if(i!=1&&!a[i-1][j])
            {
                ans[k][2]=-1,mov(i,j,-1),dfs(k+1);
                if(done)return;
                rback(b);
            }
            if(i!=5)
            {
                ans[k][2]=1,mov(i,j,1),dfs(k+1);
                if(done)return;
                rback(b);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=8;j++)
        {
            a[i][0]=100;
            cin>>a[i][j];
            if(a[i][j]==0)
                break;
        }
    }
    dfs(1);
    if(done)
        for(int i=1;i<=n;i++)
            cout<<ans[i][0]-1<<" "<<ans[i][1]-1<<" "<<ans[i][2]<<endl;
    else cout<<"-1"<<endl;
    return 0;
}