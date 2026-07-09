#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=3000;
char op;
int n,m;
int t00[N][N],t01[N][N],t10[N][N],t11[N][N];
void add(int x,int y,int d)
{
    for(int i=x;i<N;i+=lowbit(i))
        for(int j=y;j<N;j+=lowbit(j))
            t00[i][j]+=d,t10[i][j]+=d*x,t01[i][j]+=d*y,t11[i][j]+=d*x*y;
}
int sum(int x,int y)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            res+=(x+1)*(y+1)*t00[i][j]+t11[i][j]-(x+1)*t01[i][j]-(y+1)*t10[i][j];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>op>>n>>m;
    while(cin>>op)
    {
        if(op=='L')
        {
            int x,y,xx,yy,d;
            cin>>x>>y>>xx>>yy>>d;
            add(x,y,d);
            add(xx+1,yy+1,d);
            add(x,yy+1,-d);
            add(xx+1,y,-d);
        }
        else
        {
            int x,y,xx,yy;
            cin>>x>>y>>xx>>yy;
            cout<<sum(xx,yy)-sum(x-1,yy)-sum(xx,y-1)+sum(x-1,y-1)<<endl;
        }
    }
    return 0;
}