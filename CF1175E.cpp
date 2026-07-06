#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=30;
int n,m,a[N],f[N][M],p=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        a[l]=max(a[l],r);
        p=max(p,r);
    }
    for(int i=0;i<=p;i++)
    {
        a[i]=max(a[i],a[i-1]);
        f[i][0]=a[i];
    }
    for(int i=1;i<M;i++)
        for(int j=0;j<=p;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    // for(int i=1;i<=n;i++)
    //     for(int j=0;j<3;j++)
    //         printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    for(int i=1;i<=n;i++)
    {
        int l,r,ans=0;
        cin>>l>>r;
        for(int j=M-1;j>=0;j--)
            if(f[l][j]<r&&f[l][j]>=l)
                l=f[l][j],ans+=1<<j;
        if(f[l][0]>=r)cout<<ans+1<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}