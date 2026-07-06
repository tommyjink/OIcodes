#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005,P=1e9+7;
int n,m,k,f[N][N];
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
int F(int x)
{
    return qpow(x,P-2);
}
void solve()
{
    cin>>n>>m>>k;
    cout<<f[n][m]*k%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(i==j)f[i][j]=i;
            else f[i][j]=(f[i-1][j-1]+f[i-1][j])*F(2)%P;
        }
    }
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}