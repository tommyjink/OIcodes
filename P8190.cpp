#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define double long double
using namespace std;
const int N=1e6+10;
int T,K;
double a[N],p[N],b[N];
double qpow(double x,int y)
{
    double res=1.0;
    while(y)
    {
        if(y&1)res=res*x;
        x=x*x;
        y>>=1;
    }
    return res;
}
double cal(double f,int k,int s)
{
    double t=qpow(a[s],k);
    return t*f+b[s+1]*(1.0-t)/(1.0-a[s]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T>>K;
    T--;
    double f=T*1.0/2.0;
    int now=floor(f);
    a[0]=p[0]=qpow(0.5,T);
    for(int i=1;i<=T;i++)p[i]=p[i-1]*(T*1.0-i*1.0+1.0)/(i*1.0),a[i]=a[i-1]+p[i];
    b[T]=p[T]*T;
    for(int i=T-1;i>=0;i--)b[i]=b[i+1]+p[i]*i;
    int cnt=1;
    while(1)
    {
        int l=1,r=K-cnt;
        if(cal(f,r,now)<=now+1)printf("%.16llf",1.0+cal(f,r,now)),exit(0);
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(cal(f,mid,now)>now+1)r=mid;
            else l=mid+1;
        }
        f=cal(f,l,now);
        now=floor(f);
        cnt+=l;
    }
    return 0;
}