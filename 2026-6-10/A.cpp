#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y)
{
    return x/gcd(x,y)*y;
}
bool check()
{
    for(int i=1;i<=n-2;i++)
        if(gcd(a[i],gcd(a[i+1],a[i+2]))!=b[i])return false;
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    b[0]=1;
    for(int i=1;i<=n-2;i++)cin>>b[i];
    a[1]=b[1];
    a[2]=lcm(b[1],b[2]);
    for(int i=3;i<=n-2;i++)a[i]=lcm(b[i-2],lcm(b[i-1],b[i]));
    a[n-1]=lcm(b[n-3],b[n-2]);
    a[n]=b[n-2];
    if(check())for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    else cout<<"-1"<<endl;
    return 0;
}
// 2 6 6 