#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=25,M=1LL<<24,P=1e9+7;
int n,m,sum[M],b[3],f[M];
//f[i]=sum{f[i^j](j=>i)}(i is legal)
int lowbit(int x){return x&(-x);}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;for(int i=1;i<=n;i++)cin>>sum[1ll<<(i-1)];
    cin>>m;for(int i=1;i<=m;i++)cin>>b[i];
    f[0]=1ll;
    for(int i=0;i<(1ll<<n);i++)
    {
        int j=lowbit(i);
        sum[i]=sum[i^j]+sum[j];
        if(sum[i]==b[1]||sum[i]==b[2])continue;
        for(int j=i;j;j^=lowbit(j))
            f[i]=(f[i]+f[i^lowbit(j)])%P;
    }
    cout<<f[(1ll<<n)-1];
    return 0;
}