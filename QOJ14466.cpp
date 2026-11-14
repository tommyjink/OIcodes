#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005;
int n,k,g[N][N],f[N][N];
int l[N],r[N],a[N][N],b[N][N];
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        while(cin>>x&&x)
        {
            // cout<<i<<' '<<x<<"!"<<endl;
            if(x>i)f[i][x]=g[x][i+n]=f[i+n][x+n]=1;
            else g[x][i]=f[i][x+n]=g[x+n][i+n]=1;
        }
    }
    // while(1)
    // {
    //     int l,r;
    //     cin>>l>>r;
    //     if(l==0)break;
    //     cout<<f[l][r]<<" "<<g[l][r]<<endl;
    // }
    n*=2;
    for(int i=1;i<=n;i++)
        l[i]=0,r[i]=n+1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(f[i][j])l[j]=max(l[j],i);
            if(g[i][j])r[i]=min(r[i],j);
        }
    
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            if(f[i][j])a[i][j]=max(1ll,b[i+1][j]+1);
            if(g[i][j])b[i][j]=max(1ll,a[i][j-1]+1);
            a[i][j]=max(a[i][j],a[i+1][j]);
            b[i][j]=max(b[i][j],b[i][j-1]);
            for(int k=i;k<=j;k++)
            {
                if(f[i][k])a[i][j]=max(a[i][j],a[k][j]+1+b[i+1][k]);
                if(g[k][j])b[i][j]=max(b[i][j],b[i][k]+1+a[k][j-1]);
            }
        }
    }
    int ans=0,num=0;;
    int len=n/2;
    for(int i=1;i<=len+1;i++)
    {
        int j=i+len-1;
        if(a[i][j]>ans)ans=a[i][j],num=i;
        if(b[i][j]>ans)ans=b[i][j],num=j;
        // if(k)
        // {
        //     if(ans=max(ans,);
        // }
    }
    cout<<ans<<" "<<num<<endl;
    // while(1)
    // {
    //     int l,r;
    //     cin>>l>>r;
    //     if(l==0)break;
    //     cout<<f[l][r]<<" "<<g[l][r]<<endl;
    // }
    return 0;
}