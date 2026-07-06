#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e3+10,INF=1e18;
int n,P,f[N][N];
int dfs(int x,int lim)
{
    if(f[x][lim]!=INF)return f[x][lim];
    if(x==1)return 1;
    f[x][lim]=0;
    for(int i=0;x+i<=lim;i++)
    {
        int y=x+i;
        for(int j=1;j*j<=y;j++)
        {
            if(y%j)continue;
            if(j<x)f[x][lim]=(f[x][lim]+dfs(j,x-1))%P;
            if(y/j<x&&j*j!=y)f[x][lim]=(f[x][lim]+dfs(y/j,x-1))%P;
        }
    }
    f[x][lim]=(f[x][lim]+dfs(x-1,x-1))%P;
    return f[x][lim];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            f[i][j]=INF;
    cin>>n>>P;
    cout<<dfs(n,n);
    return 0;
}