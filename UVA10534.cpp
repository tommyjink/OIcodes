#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,utot=0,dtot=0,ans=0;
int a[N],up[N],down[N],su[N],sd[N];
signed main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        ans=utot=dtot=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        su[++utot]=a[1],up[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>su[utot]) su[++utot]=a[i];
            else su[lower_bound(su+1,su+1+utot,a[i])-su]=a[i];
            up[i]=utot;
        }
        sd[++dtot]=a[n],down[n]=1;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]>sd[dtot]) sd[++dtot]=a[i];
            else sd[lower_bound(sd+1,sd+1+dtot,a[i])-sd]=a[i];
            down[i]=dtot;
        }
        for(int i=1;i<=n;i++)
            ans=max(ans,min(2*up[i]-1,2*down[i]-1));
        cout<<ans<<endl;
    }
    return 0;
}