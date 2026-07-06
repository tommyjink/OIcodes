#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
const int dx[]={0,1,1,-1,-1,2,2,-2,-2};
const int dy[]={0,2,-2,2,-2,1,-1,1,-1};
const int ddx[]={1,1,-1,-1};
const int ddy[]={-1,1,-1,1};
int n,m,mp[N][N],ans=0,a[N],b[N];
void fil(int x,int y)
{
    if(x<1||y<1||x>n||y>n)
        return ;
    mp[x][y]=true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    while(m--)
    {
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='N')
            for(int i=0;i<9;i++)
                fil(x+dx[i],y+dy[i]);
        else if(c=='R')
            a[x]=b[y]=true;
        else
        {
            a[x]=b[y]=true;
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<4;j++)
                {
                    fil(x+i*ddx[j],y+i*ddy[j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((a[i]||b[j]||mp[i][j]))
                ans++;
    cout<<ans<<endl;
    return 0;
}