#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,P=998244353;
int n,a[N],f[N];
bool check(int l,int r)
{
    int now=0,res=1;
    for(int k=l;k<=r;k++)
    {
        now=max(now,a[k]);
        if(now>a[l]&&now<a[r])res=0;
        if(a[k]<a[l]&&res==0)res=1,now=0;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[i])continue;
            else if(check(j,i))f[i]=(f[i]+f[j])%P;
        }
        // printf("f[%lld]=%lld\n",i,f[i]);
    }
    a[n+1]=n+1;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(check(i,n+1))ans=(ans+f[i])%P;
    cout<<ans<<endl;
    return 0;
}