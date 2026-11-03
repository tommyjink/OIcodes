#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
struct node
{
    int x,y;
    void cal()
    {
        if(x==0)x=0,y=1;
        int d=gcd(x,y);
        x/=d;
        y/=d;
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int p=n,sum=a[n],ans=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        while(p>=i&&sum<a[p]*(i+(n-p+1)))sum+=a[p--];
        ans=max(ans,n-p);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}