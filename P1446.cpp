#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=65;
int s[3],n,m,P,fac[N],inv[N],fa[N],siz[N];
int f[N][N][N][N];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1,x=x*x%P;
    }
    return res;
}
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    // cout<<fac[N-1]<<"!"<<endl;
    for(int i=N-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    // cout<<endl;
}
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    // cout<<fac[x]<<" "<<inv[y]<<" "<<inv[x-y]<<endl;
    int res=1;
    for(int i=x;i>=x-y+1;i--)res=res*i%P;
    for(int i=1;i<=y;i++)res=res*qpow(i,P-2)%P;
    return res;
}
int getfa(int x)
{
    if(x==fa[x])return x;
    return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
    x=getfa(x),y=getfa(y);
    if(x==y)return ;
    fa[x]=y;
    siz[y]+=siz[x];
}
int work(int *a,int cnt)
{
    for(int i=0;i<=cnt;i++)
        for(int x=0;x<=s[0];x++)
            for(int y=0;y<=s[1];y++)
                for(int z=0;z<=s[2];z++)
                    f[i][x][y][z]=0;
    f[0][0][0][0]=1;
    for(int i=1;i<=cnt;i++)
    {
        for(int x=0;x<=s[0];x++)
        {
            for(int y=0;y<=s[1];y++)
            {
                for(int z=0;z<=s[2];z++)
                {
                    if(x+a[i]<=s[0])
                        f[i][x+a[i]][y][z]+=f[i-1][x][y][z],
                        f[i][x+a[i]][y][z]%=P;
                    if(y+a[i]<=s[1])
                        f[i][x][y+a[i]][z]+=f[i-1][x][y][z],
                        f[i][x][y+a[i]][z]%=P;
                    if(z+a[i]<=s[2])
                        f[i][x][y][z+a[i]]+=f[i-1][x][y][z],
                        f[i][x][y][z+a[i]]%=P;
                    }
            }
        }
    }
    return f[cnt][s[0]][s[1]][s[2]];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s[0]>>s[1]>>s[2]>>m>>P;
    n=s[0]+s[1]+s[2];
    init();
    int ans=C(n,s[0])*C(n-s[0],s[1])%P;
    // cout<<C(n,s[0])<<" "<<C(n-s[0],s[1])<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)fa[j]=j,siz[j]=1;
        for(int j=1;j<=n;j++)
        {
            int x;cin>>x;
            merge(j,x);
        }
        int v[N],cnt=0;
        for(int j=1;j<=n;j++)
            if(getfa(j)==j)v[++cnt]=siz[j];
        ans=(ans+work(v,cnt))%P;
        // for(auto j:v)cout<<j<<"!";
        // cout<<endl;
        // cout<<ans<<"!"<<endl;
    }
    // cout<<ans<<endl;
    cout<<(ans*qpow(m+1,P-2))%P<<endl;
    return 0;
}