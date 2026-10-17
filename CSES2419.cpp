#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],fac[N];
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]-fac[y]-fac[x-y];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=0;
    for(int i=1;i<N;i++)
    {
        int res=0,now=i;
        while(!(now&1))now/=2,res++;
        fac[i]=fac[i-1]+res;
    }
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!C(n-1,i-1))ans^=a[i];
    }
    cout<<ans<<endl;
    return 0;
}