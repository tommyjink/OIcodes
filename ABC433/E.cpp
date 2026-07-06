#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10,P=998244353;
string s;
int n,a[N],b[N],fac[N],invfac[N];

int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
void init()
{
    fac[0]=invfac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    invfac[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=1;i--)
        invfac[i]=invfac[i+1]*(i+1)%P;
}
int C(int x,int y)
{
    return fac[x]*invfac[x-y]%P*invfac[y]%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
        a[i+1]=s[i]-'0';
    int ans=0;
    for(int i=0;i<=8;i++)
    {
        int m=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)b[++m]=1;
            if(a[j]==i+1)b[++m]=0;
        }
        int sum=0,now=0;
        for(int j=1;j<=m;j++)
            sum+=b[j];
        sum=m-sum;
        for(int j=1;j<=m;j++)
        {
            now+=b[j];
            int x=now-1;
            int y=sum-(j-now);
            if(b[j]&&y>0)
            {
                // cout<<x<<","<<y<<endl;
                if(x<y) ans=(ans+C(x+y,y-1))%P;/*printf("ans=(ans+C(x+y,y-1)),C(%lld,%lld)=%lld\n",x+y,y-1,C(x+y,y-1));*/
                else ans=(ans+C(x+y,x+1))%P;/*printf("ans=(ans+C(x+y,x+1)),C(%lld,%lld)=%lld\n",x+y,x+1,C(x+y,x+1));*/
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*


*/