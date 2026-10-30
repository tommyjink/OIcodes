#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pdd pair<double,double>
using namespace std;
const int N=1e4+10;
const double eps=1e-8;
int n=7;
double h,t,x[N],b[N];
pdd c[N];
bool check(double mid)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(mid+b[i]<h)continue;
        double len=sqrt((mid+b[i])*(mid+b[i])-h*h);
        c[++cnt]={x[i]-len,x[i]+len};
    }
    sort(c+1,c+1+cnt);
    if(!cnt||c[1].first>0)return false;
    double now=c[1].second;
    for(int i=2;i<=cnt&&now<t;i++)
    {
        if(c[i].first>now)return false;
        now=max(now,c[i].second);
    }
    return now>=t;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>t;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>b[i];
    double l=0.0,r=max(1.0,t);
    while(!check(r))r*=2;
    while(r-l>eps)
    {
        double mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    printf("%.2lf",r);
    return 0;
}
