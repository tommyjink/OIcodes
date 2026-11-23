#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005,K=20,P=998244353;
int n,k,a[N],f[N][K];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int mx=a[i],sum=a[i];
        for(int j=i-1;j>=0;j--)
        {
            for(int t=1;t<=min({i,j+1,k});t++)
            {
                if(2*mx>sum)continue;
                f[i][t]=(f[i][t]+f[j][t-1])%P;
            }
            mx=max(mx,a[j]);
            sum+=a[j];
        }
    }
    cout<<f[n][k]<<endl;
    return 0;
}