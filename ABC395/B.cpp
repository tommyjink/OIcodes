#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100;
int n,a[N][N];
void fillblock(int x,int y,int xx,int yy,int d)
{
    for(int i=x;i<=xx;i++)
        for(int j=y;j<=yy;j++)
            a[i][j]=d;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int j=n+1-i;
        if(i<=j)
        {
            if(i&1)
                fillblock(i,i,j,j,1);
            else fillblock(i,i,j,j,0);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j])cout<<'#';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}