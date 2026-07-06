#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e6+100,M=22,K=(1ll<<M)-1;
int n,a[N],f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],f[a[i]]=a[i];
    for(int i=0;i<M;i++)
        for(int j=0;j<=K;j++)
            if((j&(1ll<<i))&&f[j^(1ll<<i)])
                f[j]=f[j^(1ll<<i)];
    for(int i=1;i<=n;i++)
        cout<<(f[K^a[i]]?f[K^a[i]]:-1)<<" ";
    return 0;
}