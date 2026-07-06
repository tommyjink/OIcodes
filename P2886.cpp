#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=300,INF=1e16;
int n,t,s,e,tot=0;
map<int,int> mp;
struct matri
{
    int m[N][N];
}a;
void init(matri &x)
{
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            x.m[i][j]=INF;
}
matri operator *(matri x,matri y)
{
    matri res;
    init(res);
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            for(int k=1;k<N;k++)
                res.m[i][j]=min(res.m[i][j],x.m[i][k]+y.m[k][j]);
    return res;
}
matri qpow(matri x,int y)
{
    matri res=x;
    y--;
    while(y)
    {
        if(y&1)res=res*x;
        y>>=1;
        x=x*x;
    }
    return res;
}
int f(int x)
{
    if(mp.count(x))return mp[x];
    else return mp[x]=++tot;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>t>>s>>e;
    init(a);
    for(int i=1;i<=t;i++)
    {
        int x,y,z;
        cin>>z>>x>>y;
        x=f(x),y=f(y);
        a.m[x][y]=z;
        a.m[y][x]=z;
    }
    // a=qpow(a,n);
    // a=a*a;
    matri ans=qpow(a,n);
    // for(int i=1;i<tot;i++)
    // {
    //     for(int j=1;j<tot;j++)
    //         cout<<ans.m[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<ans.m[f(s)][f(e)];
    return 0;
}