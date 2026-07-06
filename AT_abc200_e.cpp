#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,sum=3,i=1,j=1;
int f(int x)
{
    if(x<3)return 0;
    return (x-1)*(x-2)/2;
}
int g(int x)
{
    return f(x)-3*f(x-n)+3*f(x-2*n)-f(x-3*n);
}
int ff(int x)
{
    if(x<2)return 0;
    return x-1;
}
int gg(int x)
{
    return ff(x)-2*ff(x-n)+ff(x-2*n);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    while(k>g(sum))k-=g(sum),sum++;
    while(k>gg(sum-i))k-=gg(sum-i),i++;
    while(k>0)k-=(j<=n&&(sum-i-j)<=n&&(sum-i-j)>=1),j++;
    j--;
    cout<<i<<" "<<j<<" "<<sum-i-j<<endl;
    return 0;
}