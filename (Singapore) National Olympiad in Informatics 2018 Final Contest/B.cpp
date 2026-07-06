#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+10,LIM=500000001;
int n,m,h,ans[N],C[20005][805];
int head[N],tot=0,top;
struct node{int to,next,val;}e[N*400];
void add(int x,int y,int z){e[++tot]={y,head[x],z},head[x]=tot;}
void init()
{
    for(int i=0;i<=20000;i++)C[i][0]=1;
    for(int i=0;i<=20000;i++)
        for(int j=0;j<=800;j++)
            C[i][j+1]=min(LIM,C[i][j]*(i-j)/(j+1));
}
void dfs(int x,int now,int cnt)
{
    if(x==n)
    {
        // cout<<x<<","<<now<<","<<cnt<<endl;
        for(int i=now;i<=m-1;i++)
            ans[i]=min(LIM,C[i-now+cnt-1][cnt-1]+ans[i]);
        while(top>=0&&ans[top]==LIM)top--;
        return ;
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(now+e[i].val<=top)
            dfs(v,now+e[i].val,cnt+1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    // while(1)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     cout<<C[x][y]<<endl;
    // }
    cin>>n>>m>>h;top=m-1;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=h;j++)
        {
            int x,y;
            cin>>x>>y;x++;
            if(x<=i||y>=m)continue;
            add(i,x,y);
        }
    }
    dfs(1,0,0);
    for(int i=0;i<m;i++)
        cout<<ans[i]<<" ";
    return 0;
}