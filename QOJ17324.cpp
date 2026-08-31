#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
const double eps=1e-8;
int n;
double X[N],Y[N],V[N],P[4][N];
bool check(double M)
{
    for(int now=0;now<4;now++)
    {
        double mx=-1e6,mn=1e6;
        for(int i=1;i<=n;i++)
            mx=max(mx,P[now][i]-V[i]*M),
            mn=min(mn,P[now][i]+V[i]*M);
        if(mx>mn)return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>X[i]>>Y[i]>>V[i];
        P[0][i]=X[i]+Y[i];
        P[1][i]=X[i]-Y[i];
        P[2][i]=-X[i]+Y[i];
        P[3][i]=-X[i]-Y[i];
    }
    double l=0.0,r=1e9;
    while(r-l>eps)
    {
        // cout<<l<<" "<<r<<endl;
        double mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    printf("%.7lf",l);
    return 0;
}