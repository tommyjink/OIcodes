#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) x&(-x)
using namespace std;
const int N=3000;
int n,m,t1[N][N],t2[N][N],t3[N][N],t4[N][N];
char op;
void add(int x,int y,int w)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=m;j+=lowbit(j))
            t1[i][j]+=w,t2[i][j]+=x*w,t3[i][j]+=y*w,t4[i][j]+=x*y*w;
}
int query(int x,int y)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>op>>n>>m;
    while(cin>>op)
    {
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        if(op=='L')
        {
            int w;cin>>w;
            add(x,y,w),add(x,yy+1,-w);
            add(xx+1,y,-w),add(xx+1,yy+1,w);
        }
        if(op=='k')
        {
            cout<<query(xx,yy)-query(xx,y-1)-query(x-1,yy)+query(x-1,y-1)<<endl;
        }
    }
    
    return 0;
}