#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,M=20;
int n,K=0,sumH[N],sumT[N],sum[N];
double p,pH[N],pT[N],f[N][M],ansA=0.0,ansB=0.0;
string s;
double calH(int l,int r)
{
    if(sumT[r]-sumT[l-1])return 0.0;
    return pH[sum[r]-sum[l-1]];
}
double calT(int l,int r)
{
    if(sumH[r]-sumH[l-1])return 0.0;
    return pT[sum[r]-sum[l-1]];
}
void init( )
{
    pH[0]=pT[0]=1.0;
    pH[1]=p,pT[1]=1.0-p;
    for(int i=2;i<=n;i++)pH[i]=pH[i-1]*p;
    for(int i=2;i<=n;i++)pT[i]=pT[i-1]*(1.0-p);
    for(int i=1;i<=n;i++)
        sumH[i]=sumH[i-1]+(s[i]=='H'),
        sumT[i]=sumT[i-1]+(s[i]=='T'),
        sum[i]=sum[i-1]+(s[i]=='?');
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>p>>s;s=" "+s;
    init();
    f[0][M-1]=1;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int k=0;k<j;k++)
            {
                int L=(1ll<<k);
                if(i+L<=n)f[i+L][k]+=f[i][j]*(calH(i+1,i+L)+calT(i+1,i+L));
                if(i+2*L<=n)
                {
                    double A=calH(i+1,i+L)*calT(i+L+1,i+2*L);
                    double B=calT(i+1,i+L)*calH(i+L+1,i+2*L);
                    f[i+2*L][M-1]+=f[i][j]*(A+B);
                    ansA+=A*f[i][j],ansB+=B*f[i][j];
                }
            }
        }
    }
    printf("%.6lf %.6lf",ansA,ansB);
    // cout<<ansA<<" "<<ansB<<endl;
    return 0;
}