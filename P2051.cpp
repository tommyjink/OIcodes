#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,P=9999973;
int n,m,f[N][N][N],ans=0;
int C(int x)
{
    return (x*(x-1)/2)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    //f[i][j][k]+=f[i-1][j][k];不放done
    //f[i][j][k]+=f[i-1][j-1][k]*(m-(j-1)-k);放一个在空done
    //f[i][j][k]+=f[i-1][j+1][k-1]*(j+1);放一个在一个done
    //f[i][j][k]+=f[i-1][j-2][k]*C(m-(j-2)-k,2);放两个在空
    //f[i][j][k]+=f[i-1][j+2][k-2]*C(j+2,2);放两个在一个
    //f[i][j][k]+=f[i-1][j][k-1]*j*(m-j-(k-1));放一个在一个，另一个在空
    f[1][0][0]=1,f[1][1][0]=m,f[1][2][0]=C(m);
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=m-j;k++)//m-j-k>=0  ==> k<=m-j
            {
                f[i][j][k]+=f[i-1][j][k];
                if(j-1>=0&&m-(j-1)-k>=0)   
                    f[i][j][k]+=f[i-1][j-1][k]*(m-(j-1)-k);
                if(j+1<=m&&k-1>=0)
                    f[i][j][k]+=f[i-1][j+1][k-1]*(j+1);
                if(j-2>=0&&m-(j-2)-k>=0)
                    f[i][j][k]+=f[i-1][j-2][k]*C(m-(j-2)-k);
                if(j+2<=m&&k-2>=0)
                    f[i][j][k]+=f[i-1][j+2][k-2]*C(j+2);
                if(k-1>=0&&m-j-(k-1)>=0)
                    f[i][j][k]+=f[i-1][j][k-1]*(j%P)*(m-j-(k-1));
                f[i][j][k]%=P;
                // printf("f[%lld][%lld][%lld]=%lld\n",i,j,k,f[i][j][k]);
            }
        }
    }
    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            ans=(ans+f[n][i][j])%P;
    cout<<ans<<endl;
    return 0;
}