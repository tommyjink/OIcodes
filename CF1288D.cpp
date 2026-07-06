#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=10,L=1024;
int n,m,a[N][M],b[N],f[L],a1,a2;
bool check(int x)
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        b[i]=0;
        for(int j=1;j<=m;j++)
            if(a[i][j]>=x)b[i]|=(1ll<<(j-1));
        f[b[i]]=i;
    }
    for(int j=0;j<m;j++)
        for(int i=0;i<(1ll<<m);i++)
            if(!(i&(1ll<<j)))f[i]=max(f[i],f[i^(1ll<<j)]);
    int v=(1ll<<m)-1;
    for(int i=1;i<=n;i++)
        if(f[v^b[i]])
        {
            a1=i,a2=f[v^b[i]];
            return true;
        }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int l=-1e9,r=1e18;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    // check(0);
    cout<<a1<<" "<<a2<<endl;
    return 0;
}
/*
4 2
0 0
0 0
0 0
0 0

4 4
*/