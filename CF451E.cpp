#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
int n,s;
int f[25];
int qpow(int a,int b)
{
    int res=1;
    a%=MOD;
    while(b)
    {
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
int C(int n,int k)
{
    if(k<0||n<k||n<0)return 0;
    if(k==0||n==k)return 1;
    if(k>n-k)k=n-k;
    int up=1,down=1;
    for(int i=0;i<k;i++)
    {
        up=up*((n-i)%MOD)%MOD;
        down=down*(i+1)%MOD;
    }
    return up*qpow(down,MOD-2)%MOD;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++)cin>>f[i];
    int ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        int p=0,cnt=0;
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1)
            {
                p+=(f[j]+1);
                cnt++;
            }
        }
        int cur=C(s-p+n-1,n-1);
        if(cnt&1)ans=(ans-cur+MOD)%MOD;
        else ans=(ans+cur)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}