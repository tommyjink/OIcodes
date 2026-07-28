#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205,P=998244353;
int n,a[N][N],b[N][N];
bitset<N> c[N];
int gs()
{
    int r=1;
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=r;j<=n;j++)
            if(c[j][i])now=j;
        if(!now)continue;
        swap(c[r],c[now]);
        for(int j=r+1;j<=n;j++)
            if(c[j][i])c[j]^=c[r];
        r++;
    }
    return r-1;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>b[i][j];
    int ans=0;
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=n;k++)
                c[i][k]=a[i][k];
            c[i][i]=c[i][i]^b[i][j];
        }
        ans+=n-gs();
    }
    cout<<qpow(2ll,ans)<<endl;
    return 0;
}