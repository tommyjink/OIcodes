#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7,N=1e5+10;
int n,k,l,h,f[N];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>l>>h;
    int tag=bool(l<=k&&k<=h);
    l=(l+k-1)/k,h=h/k;
    if(l>h)
    {
        cout<<"0"<<endl;
        return 0;
    }
    // cout<<l<<" "<<h<<endl;
    for(int i=1;i<=h-l+1;i++)
    {
        int num=(h)/i-(l-1)/i;
        f[i]=((qpow(num,n)-num)%P+P)%P;
    }
    // cout<<f[1]<<endl;
    for(int i=h-l+1;i>=1;i--)
        for(int j=2;i*j<=h-l+1;j++)
            f[i]=((f[i]-f[i*j])%P+P)%P;
    cout<<f[1]+tag;
    return 0;
}