#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3010,M=10010;
int T,n,p,mod,mx;
int qn[M],qp[M],ans[M],vis[M];
int dp[N][N],f[N],g[N],h[N];

void mul(int lim)
{
    for(int i=0;i<=lim;i++)h[i]=0;
    for(int i=0;i<=lim;i++)
        if(f[i])
            for(int j=0;i+j<=lim;j++)
                if(g[j])
                    h[i+j]=(h[i+j]+(__int128)f[i]*g[j])%mod;
    for(int i=0;i<=lim;i++)f[i]=h[i];
}

void work()
{
    for(int i=0;i<=mx;i++)
        for(int j=0;j<=mx;j++)
            dp[i][j]=0;
    for(int i=0;i<=mx;i++)dp[1][i]=1%mod;
    for(int i=2;i<=mx;i++)
    {
        int lim=mx/i;
        for(int j=0;j<=lim;j++)f[j]=g[j]=0;
        f[0]=1;
        g[0]=1;
        for(int j=1;j<=lim;j++)
            if(j<=mx/(i-1))g[j]=dp[i-1][j];
        // cout<<"i="<<i<<":!!"<<endl;
        // for(int j=1;j<=lim;j++)
        //     cout<<g[j]<<" ";
        // cout<<endl;
        // for(int j=1;j<=lim;j++)
        //     cout<<f[j]<<" ";
        // cout<<endl;
        mul(lim);
        // for(int j=1;j<=lim;j++)
        //     cout<<f[j]<<" ";
        // cout<<endl;
        for(int j=1;j*2<=i-1;j++)
        {
            int k=i-1-j;
            for(int l=0;l<=lim;l++)g[l]=0;
            g[0]=1;
            if(j<k)
            {
                for(int l=1;l<=lim;l++)
                    if(l<=mx/j&&l<=mx/k)
                        g[l]=(__int128)dp[j][l]*dp[k][l]%mod;
            }
            else
            {
                for(int l=1;l<=lim;l++)
                    if(2*l<=mx/j)
                        g[l]=dp[j][2*l];
            }
            // cout<<"j="<<j<<":"<<endl;
            // cout<<"    f:";
            // for(int ii=1;ii<=lim;ii++)
            //     cout<<f[ii]<<" ";
            // cout<<endl;
            // cout<<"    g:";
            // for(int ii=1;ii<=lim;ii++)
            //     cout<<g[ii]<<" ";
            // cout<<endl;

            mul(lim);
            // cout<<"mul,f:";
            // for(int ii=1;ii<=lim;ii++)
            //     cout<<f[ii]<<" ";
            // cout<<endl;
        }
        for(int j=1;j<=lim;j++)dp[i][j]=f[j];
    }
    // for(int i=1;i<=mx;i++)
    //     for(int j=1;j<=mx/i;j++)
    //         printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("signature.in","r",stdin);
    freopen("signature.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
        cin>>qn[i]>>qp[i];
    for(int i=1;i<=T;i++)
        if(!vis[i])
        {
            mod=qp[i];
            mx=0;
            for(int j=i;j<=T;j++)
                if(qp[j]==mod)
                    mx=max(mx,qn[j]);
            work();
            for(int j=i;j<=T;j++)
                if(qp[j]==mod)
                {
                    vis[j]=1;
                    ans[j]=dp[qn[j]][1]%mod;
                }
        }
    for(int i=1;i<=T;i++)
        cout<<ans[i]<<endl;
    return 0;
}
