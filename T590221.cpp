#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const double E=1e-7;
const int N=1e6;
int n,k;
double a[N];
bool check1(double x)
{
    double now=1.0;
    int cnt=0,p=0;
    for(int i=1;i<=n;i++)
    {
        now*=a[i];
        if(pow(now,1.0/(i-p))>=x)
            now=1.0,cnt++,p=i;
    }
    return cnt>=k;
}
bool check2(double x)
{
    double now=0.0;
    int cnt=0,p=0;
    for(int i=1;i<=n;i++)
    {
        now+=a[i]*a[i];
        if(sqrt(now/(i-p))>=x)
            now=0.0,cnt++,p=i;
    }
    return cnt>=k;
}
double solve1()
{
    double l=1.0,r=1000000.0;
    while(r-l>=E)
    {
        double mid=(l+r)/2.0;
        if(check1(mid))l=mid;
        else r=mid;
    }
    return l;
}
double solve2()
{
    double l=1.0,r=1000000.0;
    while(r-l>=E)
    {
        double mid=(l+r)/2.0;
        if(check2(mid))l=mid;
        else r=mid;
    }
    return l;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    printf("%.6lf %.6lf",solve1(),solve2());
    return 0;
}