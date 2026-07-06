#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100,M=30;
int n,a[N],b[N][M+10],c[N][M+10];
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    return y==0?x:gcd(y,x%y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        b[i][0]=a[i+1],
        c[i][0]=a[i-1];
    for(int j=1;j<=M;j++)
        for(int i=1;i<=n;i++)
            b[i][j]=gcd(b[i][j-1],b[min(n,i+(1ll<<(j-1)))][j-1]),
            c[i][j]=gcd(c[i][j-1],c[max(0ll,i-(1<<(j-1)))][j-1]);
    for(int i=1;i<=n;i++)
    {
        int l=i,r=i;
        for(int j=M;j>=0;j--)
            if(b[i][j]);
    }
    return 0;
}