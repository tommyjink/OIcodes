#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],ans;
int cal(int x,int y){return max(0ll,y-x);}
signed main()
{
    freopen("ridge.in","r",stdin);freopen("ridge.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i],ans+=cal(a[i-1],a[i]);
    while(q--)
    {
        int x,y;cin>>x>>y;
        ans-=cal(a[x-1],a[x]);
        if(x<n)ans-=cal(a[x],a[x+1]);
        a[x]=y;ans+=cal(a[x-1],a[x]);
        if(x<n)ans+=cal(a[x],a[x+1]);
        cout<<ans<<endl;
    }
    return 0;
}
