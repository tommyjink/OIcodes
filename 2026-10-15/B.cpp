#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e6+10,P=998244353;
int l,r,f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>l>>r;
    f[l]=1;
    int sum=1;
    for(int i=l+1;i<=r;i++)
    {
        f[i]=sum;
        sum=(sum+f[i])%P;
        if(i>=l+l)sum=(sum-f[i-l]+P)%P;
    }
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans=(ans+f[i])%P;
        for(int j=i*2;j<=r;j+=i)
        {
            f[j]=(f[j]-f[i]+P)%P;
        }
    }
    cout<<ans<<endl;
    return 0;
}