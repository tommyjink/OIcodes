#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=505,P=1e9+7;
int n,id[N][N];
string s[N];
struct node{int x,y;};
vector<node> c[2*N];
int f[2][N][N],now=0;
bool check(int x,int y)
{
    return (x>=1&&y>=1&&x<=n&&y<=n);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i],s[i]=" "+s[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i+j-1].push_back({i,j}),id[i][j]=c[i+j-1].size()-1;
    if(s[1][1]==s[n][n])f[now^1][0][0]=1;
    for(int i=2;i<=n;i++,now^=1)
    {
        for(int j=0;j<c[i].size();j++)
        {
            for(int k=0;k<c[2*n-i].size();k++)
            {
                f[now][j][k]=0;
                int ax=c[i][j].x,ay=c[i][j].y;
                int bx=c[2*n-i][k].x,by=c[2*n-i][k].y;
                if(s[ax][ay]!=s[bx][by])continue;
                int cx[2]={ax-1,ax};
                int cy[2]={ay,ay-1};
                int dx[2]={bx+1,bx};
                int dy[2]={by,by+1};
                for(int ii=0;ii<2;ii++)
                {
                    for(int jj=0;jj<2;jj++)
                    {
                        if(check(cx[ii],cy[ii])&&check(dx[jj],dy[jj]))
                        {
                            int id1=id[cx[ii]][cy[ii]];
                            int id2=id[dx[jj]][dy[jj]];
                            f[now][j][k]=(f[now][j][k]+f[now^1][id1][id2])%P;
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+f[now^1][i-1][i-1])%P;
    cout<<ans<<endl;
    return 0;
}