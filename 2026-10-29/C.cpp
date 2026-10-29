#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505;
int n,m,k,g[N][N],val[N][N];
int a[N][N],cnt[N],f[N][N],mx=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int base=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            if(g[i][j])a[i][++cnt[i]]=j;
        }
        int c=a[i][cnt[i]]-a[i][1]+1;
        base+=c;
        val[i][0]=0;
        val[i][cnt[i]]=c;
        for(int j=1;j<=cnt[i]-1;j++)
        {
            int now=m,len=cnt[i]-j;
            for(int k=1;k<=cnt[i]-len+1;k++)
            {
                now=min(now,a[i][k+len-1]-a[i][k]+1);
            }
            // cout<<i<<","<<j<<":"<<c<<","<<now<<endl;
            val[i][j]=c-now;
        }
    }
    cin>>k;
    for(int i=1;i<=n;i++)
    {

        for(int j=0;j<=cnt[i];j++)
        {
            // cout<<j<<"!!"<<endl;
            for(int t=j;t<=k;t++)
            {
                // cout<<k<<"??"<<endl;
                // cout<<j<<","<<t<<" "<<f[i-1][t-j]<<":"<<val[i][j]<<endl;
                f[i][t]=max(f[i][t],f[i-1][t-j]+val[i][j]);
                mx=max(mx,f[i][t]);
            }
        }
    }
    
    // cout<<base<<","<<mx<<endl;
    cout<<base-mx<<endl;
    // for(int i=1;i<=n;i++)
    //     for(int j=0;j<=cnt[i];j++)
    //         cout<<i<<" "<<j<<":"<<val[i][j]<<endl;
    return 0;
}