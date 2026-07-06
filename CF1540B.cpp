#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205,P=1e9+7;
int n,head[N],tot=0,f[N][30],g[N][N];
int dep[N],inv[N*2],fac[N*2];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
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
void dfs(int x,int fa)
{
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
}
void init()
{
    for(int i=1;i<=29;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
}
inline int C(int x,int y)
{
    if(x<y)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=29;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])x=f[x][i];
    if(x==y)return x;
    for(int i=29;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<2*N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[2*N-1]=qpow(fac[2*N-1],P-2);
    for(int i=2*N-2;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // while(1)
    // {
    //     int a,b;
    //     cin>>a>>b;
    //     cout<<C(a+b-1,b)<<endl;
    //     cout<<qpow(2,a+b-1)<<endl;
    //     cout<<C(a+b-1,b)*qpow(qpow(2,a+b-1),P-2)%P<<endl;

    // }
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=j-1;k++)
                g[i][j]=(g[i][j]+C(i+k-1,i-1)*qpow(qpow(2,i+k),P-2)%P)%P;
    // while(1)
    // {
    //     int a,b;
    //     cin>>a>>b;
    //     cout<<g[a][b]<<endl;
    // }
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    int ans=0;
    for(int root=1;root<=n;root++)
    {
        dfs(root,0);
        init();
        int res=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                int o=lca(i,j);
                if(o==i){res=(res+1)%P;continue;}
                else if(o==j)continue;
                int a=dep[i]-dep[o];
                int b=dep[j]-dep[o];
                res=(res+g[a][b])%P;
                // cout<<i<<","<<j<<":"<<C(a+b-1,b)*qpow(2,a+b-1)%P<<endl;
                // cout<<a<<"<<<<"<<b<<endl;
            }
        }
        // cout<<root<<":"<<res<<endl;
        ans=(ans+res*qpow(n,P-2)%P)%P;
    }
    cout<<ans<<endl;
    return 0;
}