#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,xx[N],yy[N],x[N],y[N];
int cal(int lim)
{
    for(int i=1;i<=n;i++)
    {
        xx[i]=x[i],yy[i]=y[i];
        if(x[i]>lim&&y[i]>lim)return 1000*1000;
    }
    int now=n/2;
    for(int i=1;i<=n;i++)
        if(yy[i]>lim)now--,swap(xx[i],yy[i]);
    if(now<0)return 1000*1000;
    for(int i=1;i<=n;i++)
        if(xx[i]<=lim&&xx[i]>yy[i]&&now>0)
            now--,swap(xx[i],yy[i]);
    int res=0;
    for(int i=1;i<=n;i++)
        res+=xx[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    int ans=1000*1000;
    for(int i=1;i<=1000;i++)
    {
        ans=min(ans,i*cal(i));
        // cout<<i<<" "<<cal(i)<<endl;
    }
    cout<<ans<<endl;
    return 0;
}