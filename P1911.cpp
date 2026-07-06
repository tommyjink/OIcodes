#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e3+10;
int n,a[N][N],tot=0,mp[N*N],cnt=0;
void dfs(int x_1,int y_1,int d,int x,int y)
{
    // printf("x_1,y_1,d,x,y=%lld,%lld,%lld,%lld,%lld\n",x_1,y_1,d,x,y);
    if(d==2)
    {
        tot++;
        for(int i=x_1;i<=x_1+d-1;i++)
            for(int j=y_1;j<=y_1+d-1;j++)
                if(i!=x||j!=y)a[i][j]=tot;
        return;
    }
    int midx=x_1+d/2-1;
    int midy=y_1+d/2-1;
    int tag[5]={1,1,1,1,1};
    int tmp=++tot;
    if(x<=midx)tag[3]=tag[4]=0;
    else tag[1]=tag[2]=0;
    if(y<=midy)tag[2]=tag[4]=0;
    else tag[1]=tag[3]=0;
    int xx=x_1+d/2-1,yy=y_1+d/2-1;
    if(!tag[1])dfs(x_1,y_1,d/2,xx,yy),a[xx][yy]=tmp;
    else dfs(x_1,y_1,d/2,x,y);
    if(!tag[2])dfs(x_1,y_1+d/2,d/2,xx,yy+1),a[xx][yy+1]=tmp;
    else dfs(x_1,y_1+d/2,d/2,x,y);
    if(!tag[3])dfs(x_1+d/2,y_1,d/2,xx+1,yy),a[xx+1][yy]=tmp;
    else dfs(x_1+d/2,y_1,d/2,x,y);
    if(!tag[4])dfs(x_1+d/2,y_1+d/2,d/2,xx+1,yy+1),a[xx+1][yy+1]=tmp;
    else dfs(x_1+d/2,y_1+d/2,d/2,x,y);
}
signed main()
{
    // freopen("P1911.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y;
    cin>>n>>x>>y;
    n=2<<(n-1);
    // cout<<n<<endl;
    dfs(1,1,n,x,y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0)cout<<"0 ";
            else
            {
                if(!mp[a[i][j]])
                    mp[a[i][j]]=++cnt;
                cout<<mp[a[i][j]]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}