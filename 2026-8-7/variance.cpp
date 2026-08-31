#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],sum[N],bx[N],by[N],d[N],cx[N],cy[N];
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
void print(int x,int y)
{
    int d=gcd(x,y);
    x/=d,y/=d;
    if(y==1)cout<<x<<" ";
    else cout<<x<<"/"<<y<<" ";
}
signed main()
{
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum[i]=sum[i-1]+a[i],d[i]=a[i]*a[i]+d[i-1];
    for(int i=1;i<=n;i++)
        bx[i]=sum[i],by[i]=i;
    for(int i=1;i<=n;i++)
    {
        cx[i]=d[i]*i+bx[i]*bx[i]-2*bx[i]*sum[i];
        cy[i]=i*i;
    }
    for(int i=1;i<=n;i++)
    {
        print(sum[i],1);
        print(bx[i],by[i]);
        print(cx[i],cy[i]);
        cout<<endl;
    }
    return 0;
}