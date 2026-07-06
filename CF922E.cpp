#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10,M=1e4+10;
int n,W,B,X,c[N],cost[N],f[N][M],sum[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>W>>B>>X;
    for(int i=1;i<=n;i++)
        cin>>c[i],sum[i]=sum[i-1]+c[i];
    for(int i=1;i<=n;i++)
        cin>>cost[i];
    memset(f,128,sizeof(f));
    f[0][0]=W;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum[i];j++)
        {
            f[i][j]=-1e9;
            for(int k=0;k<=min(j,c[i]);k++)
            {
                if(f[i-1][j-k]-k*cost[i]<0||f[i-1][j-k]<0)continue;
                f[i][j]=max(f[i][j],min(f[i-1][j-k]-k*cost[i]+X,W+B*j));
                // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
            }
        }
    }
    for(int i=sum[n];i>=1;i--)
        if(f[n][i]>=0)
        {
            cout<<i<<endl;
            return 0;
        }
    cout<<"0"<<endl;
    return 0;
}