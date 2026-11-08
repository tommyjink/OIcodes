#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20,M=5e6+10,P=998244353;
int n,m,g[N][N],f[M][N];
void add(int &x,int y)
{
    x=(x+y)%P;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x][y]=true;
        g[y][x]=true;
    }
    for(int i=1;i<=n;i++)
        f[1<<(i-1)][i]=1;
    for(int s=1;s<(1<<n);s++)
    {
        for(int i=1;i<=n;i++)
        {
            if(!(s&(1<<(i-1))))continue;
            for(int j=1;j<=n;j++)
            {
                if(s&(1<<(j-1)))continue;
                if(g[i][j]||i<j)
                    add(f[s|(1<<(j-1))][j],f[s][i]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        cout<<f[(1<<n)-1][i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)add(ans,f[(1<<n)-1][i]);
    // cout<<ans<<endl;
    cout<<(ans*qpow(2,P-2)%P*m%P)<<endl;
    return 0;
}