#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5000,M=70,mod=998244353;
int n,m,s,lim,ans;
int a[N];
signed f1[M],f2[M][M],f3[M][M][M];
signed g1[M],g2[M][M],g3[M][M][M];

void dfs(int x,int len,int p,int q,int r)
{
    if(x==n+1)
    {
        if(len)ans++;
        return;
    }
    dfs(x+1,len,p,q,r);
    if(len<3)
    {
        if(len==0)dfs(x+1,1,a[x],0,0);
        else if(len==1)dfs(x+1,2,p,a[x],0);
        else dfs(x+1,3,p,q,a[x]);
    }
    else if((p^q^r^a[x])!=s)dfs(x+1,len+1,q,r,a[x]);
}

void solve1()
{
    ans=0;
    dfs(1,0,0,0,0);
    cout<<ans%mod<<endl;
}

void add(signed &x,int y)
{
    x=(x+y)%mod;
}

void addans(int x)
{
    ans+=x;
    ans%=mod;
}

void solve2()
{
    ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<lim;j++)g1[j]=f1[j];
        for(int j=0;j<lim;j++)
            for(int k=0;k<lim;k++)g2[j][k]=f2[j][k];
        for(int j=0;j<lim;j++)
            for(int k=0;k<lim;k++)
                for(int l=0;l<lim;l++)g3[j][k][l]=f3[j][k][l];
        int x=a[i];
        add(f1[x],1);
        addans(1);
        for(int j=0;j<lim;j++)
        {
            add(f2[j][x],g1[j]);
            addans(g1[j]);
        }
        for(int j=0;j<lim;j++)
            for(int k=0;k<lim;k++)
            {
                add(f3[j][k][x],g2[j][k]);
                addans(g2[j][k]);
            }
        for(int j=0;j<lim;j++)
            for(int k=0;k<lim;k++)
                for(int l=0;l<lim;l++)
                    if((j^k^l^x)!=s)
                    {
                        add(f3[k][l][x],g3[j][k][l]);
                        addans(g3[j][k][l]);
                    }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    lim=1<<m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=24)solve1();
    else if(lim<=64&&n<=200)solve2();
    else cout<<0<<endl;
    return 0;
}
