#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,M=10210;
int n,m,p,lim;
int a[N],f[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]=max(a[x],y);
    }
    for(int i=1;i<=100;i++)
        if(a[i]&&(!p||a[i]*p>a[p]*i||(a[i]*p==a[p]*i&&i<p)))p=i;
    lim=10000+2*p;
    for(int i=1;i<=100;i++)
        if(a[i])
            for(int j=i;j<=lim;j++)
                f[j]=max(f[j],f[j-i]+a[i]);
    if(m<=lim)
    {
        cout<<f[m]<<endl;
        return 0;
    }
    int x=10000+p+(m-10000-p)%p;
    cout<<f[x]+(m-x)/p*a[p]<<endl;
    return 0;
}
