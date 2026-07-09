#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=30,M=1e5+10;
int n,m,a[M],b[M],A[N][N],B[N][N];
int x[N*N],y[N*N],cnt=0,AA[M];
bool check()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            B[i][j]+=B[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            B[i][j]+=B[i-1][j];
    for(int i=1;i<=n;i++)
    {
        if(B[i][n]>a[i])return false;
        if(B[n][i]>b[i])return false;
    }
    return true;
}
void solve2()
{
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
        cin>>b[i],b[i]+=b[i-1];
    int now=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            now+=x;
            AA[now]+=z;
        }
    }
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("challenge.in","r",stdin);
    freopen("challenge.out","w",stdout);
    cin>>n>>m;
    if(n>20)solve2(),exit(0);
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
        cin>>b[i],b[i]+=b[i-1];
    int now=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        now+=x;
        A[now][y]+=z;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(A[i][j])x[++cnt]=i,y[cnt]=j;
    int ans=0;
    for(int s=0;s<(1ll<<cnt);s++)
    {
        int res=0;
        for(int i=1;i<=cnt;i++)
        {
            if(s&(1ll<<(i-1)))
                B[x[i]][y[i]]=1,res++;
            else B[x[i]][y[i]]=0;
        }
        if(check())ans=max(ans,res);
    }
    cout<<ans<<endl;
    
    return 0;
}