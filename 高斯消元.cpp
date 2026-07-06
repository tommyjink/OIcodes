#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const double eps=1e-7;
int n;
double f[100][100];
void gauss()
{
    for(int j=1;j<=n;j++)
    {
        for(int i=j;i<=n;i++) if(f[i][j]) {swap(f[i],f[j]);break;}
        if(fabs(f[j][j])<eps) {printf("No Solution\n");exit(0);}
        for(int i=1;i<=n;i++)
        {
            if(i==j) continue;
            double K=f[i][j]/f[j][j];
            for(int k=1;k<=n+1;k++) f[i][k]-=K*f[j][k];
        }
    }
    for(int i=1;i<=n;i++) f[i][n+1]/=f[i][i];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}