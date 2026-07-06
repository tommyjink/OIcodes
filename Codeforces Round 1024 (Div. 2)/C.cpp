#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,a[N][N];
void solve()
{
    cin>>n;
    int x=500,y=500,now=0,cnt=n*n-1,k=1,num=0,lx=500,ly=500,rx=500,ry=500;
    while(cnt>0)
    {
        for(int i=1;i<=(k+1)/2;i++)
        {
            x+=dx[now],y+=dy[now];
            lx=min(lx,x),ly=min(ly,y);
            rx=max(rx,x),ry=max(ry,y);
            a[x][y]=++num;
            cnt--;
            if(cnt==0)break;
        }
        now=(now+1)%4,k++;
    }
    for(int i=lx;i<=rx;i++)
    {
        for(int j=ly;j<=ry;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}