#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3010,M=310;
int n,m,sum[M];
double p[N][M],f[N],a[M],ans;

double calc(int id,int k)
{
    for(int i=0;i<=k;i++)f[i]=0;
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        double q=p[i][id];
        for(int j=min(i,k);j>=1;j--)
            f[j]=f[j]*(1-q)+f[j-1]*q;
        f[0]*=1-q;
    }
    double res=0,s=0;
    for(int i=0;i<k;i++)
    {
        res+=i*f[i];
        s+=f[i];
    }
    res+=k*(1-s);
    s+=f[k];
    a[id]=1-s;
    if(a[id]<0)a[id]=0;
    if(a[id]>1)a[id]=1;
    return res;
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            p[i][j]=x/1000.0;
            sum[j]+=x;
        }
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int k=sum[i]/1000;
        cnt+=k;
        ans+=calc(i,k);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     double f[N];
    //     for(int j=1;j<=min(i,cnt);j++)
    //     {

    //     }
    // }
    sort(a+1,a+m+1);
    for(int i=m-(n-cnt)+1;i<=m;i++)ans+=a[i];
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
