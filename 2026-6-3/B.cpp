#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=6e5+10,M=20,mod=1e9+7;

int n,ans=0;
int dpf[M+1][N],dpg[M+1][N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,sumf=0,sumg=0;
        cin>>a;
        a%=mod;
        for(int j=0;j<M;j++)
            if((i>>j)&1)
            {
                sumf=(sumf+dpf[j][i^(1<<j)])%mod;
                sumg=(sumg+dpg[j][i^(1<<j)])%mod;
            }
        int f=(a*a%mod+sumg*sumg%mod)%mod;
        int g=(sumf+f*f%mod)%mod;
        dpf[0][i]=f*f%mod;
        dpg[0][i]=g;
        for(int j=0;j<M;j++)
        {
            dpf[j+1][i]=dpf[j][i];
            dpg[j+1][i]=dpg[j][i];
            if((i>>j)&1)
            {
                dpf[j+1][i]=(dpf[j+1][i]+dpf[j][i^(1<<j)])%mod;
                dpg[j+1][i]=(dpg[j+1][i]+dpg[j][i^(1<<j)])%mod;
            }
        }
        ans=(ans+i*f%mod*g)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
