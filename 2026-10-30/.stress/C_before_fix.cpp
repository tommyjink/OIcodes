#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pdd pair<double,double>
using namespace std;
const int N=1e4+10;
const double eps=1e-5;
int n=7;
double h,t,x[N],b[N];
pdd c[N];
bool check(double mid)
{
    for(int i=1;i<=n;i++)
    {
        double len=sqrt((mid+b[i])*(mid+b[i])-h*h);
        c[i]={x[i]-len,x[i]+len};
    }
    sort(c+1,c+1+n);
    if(c[1].first>0||c[n].second<t)return false;
    double now=c[1].second;
    for(int i=2;i<=n;i++)
    {
        if(c[i].first>now)return false;
        now=max(now,c[i].second);
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>t;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>b[i];
    double l=0.0,r=t;
    while(r-l>eps)
    {
        double mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    l+=0.005;
    printf("%.2lf",l);
    return 0;
}