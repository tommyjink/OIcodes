#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
const double eps=1e-9;
const double INF=1e18;
int n,k;
double p,f[N][30],ans=0.0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)f[i][0]=1-p;
    for(int i=1;i<=n;i++)
    {
        if(i==1)f[0][0]=1;
        else
        { 
            int p=i;
            while(p<n&&f[i][p]-f[i-1][p]<eps)p++;
            if(f[i][p])
            {
                f[i][p]+=f[i-1][p];
            }
        }
        ans+=f[i][i];
    }
    cout<<ans<<endl;
    return 0;
}