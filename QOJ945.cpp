#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=20,M=5e6+10,P=998244353;
int n,m,g[N][N],dp[M],ok[M],l[N];
int k[M];
void add(int &x,int y)
{
    x=(x+y)%P;
}
int qpow(int x,int y)
{
    x=(x+P)%P;
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
int cnt(int x)
{
    return __builtin_popcountll(x);
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
        l[x]|=(1<<(y-1));
        l[y]|=(1<<(x-1));
    }
    for(int i=1;i<=n;i++)
        k[1<<(i-1)]=i;
    ok[0]=1;
    for(int s=1;s<(1<<n);s++)
    {
        int p=lowbit(s);
        if(ok[s^p]&&!(l[k[p]]&(s^p)))
            ok[s]=1;
    }
    dp[0]=1;
    for(int s=1;s<(1<<n);s++)
    {
        for(int t=s;t>0;t--,t=s&t)
        {
            if(ok[t])
            {
                if(cnt(t)&1)add(dp[s],dp[s^t]);
                else add(dp[s],P-dp[s^t]);
            }
        }
    }
    cout<<dp[(1<<n)-1]*qpow(2,P-2)%P*m%P<<endl;
    return 0;
}