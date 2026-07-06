#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],f[N][30],g[N][30];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i][0]=a[i];
        g[i][0]=i;
    }
    for(int i=1;i<30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[j][i]=f[f[j][i-1]][i-1];
            g[j][i]=g[f[j][i-1]][i-1]+g[j][i-1];
        }
    }
    while(q--)
    {
        int t,b,res=0;
        cin>>t>>b;
        for(int i=29;i>=0;i--)
            if(t&(1ll<<i))
                res+=g[b][i],b=f[b][i];
        cout<<res<<endl;
    }
    return 0;
}