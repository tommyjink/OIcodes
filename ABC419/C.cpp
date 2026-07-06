#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x[N],y[N],X=0,Y=0,xx=1e10,yy=1e10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i],X=max(X,x[i]),Y=max(Y,y[i]),xx=min(xx,x[i]),yy=min(yy,y[i]);
    X=(X+xx)/2,Y=(Y+yy)/2;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,max(abs(x[i]-X),abs(y[i]-Y)));
    cout<<ans<<endl;
    return 0;
}