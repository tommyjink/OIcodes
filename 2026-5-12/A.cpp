#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q,v[N],l[N],a[N];
ll sv[N],sl[N],ans[N];
int ask1(ll x)
{
    int L=1,R=n,res=0;
    while(L<=R)
    {
        int mid=(L+R)>>1;
        if((ll)v[mid]<=x)res=mid,L=mid+1;
        else R=mid-1;
    }
    return res;
}
int ask2(ll x,int t)
{
    int L=1,R=n,res=0;
    while(L<=R)
    {
        int mid=(L+R)>>1;
        if((ll)l[mid]*t<=x)res=mid,L=mid+1;
        else R=mid-1;
    }
    return res;
}
void print(ll x)
{
    if(!x){cout<<0;return;}
    vector<int> s;
    while(x)
    {
        s.emplace_back(x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    for(auto i:s)cout<<i;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>l[i];
    sort(v+1,v+n+1);
    sort(l+1,l+n+1);
    sv[0]=sl[0]=0;
    for(int i=1;i<=n;i++)sv[i]=sv[i-1]+v[i],sl[i]=sl[i-1]+l[i];
    cin>>q;
    for(int i=1;i<=q;i++)cin>>a[i];
    for(int i=1;i<=q;i++)
    {
        int t=a[i],L=0,R=n;
        ll p=0;
        while(L<=R)
        {
            int mid=(L+R)>>1;
            int j=n-mid;
            ll a1=(mid?(ll)v[mid]:(ll)-4e18);
            ll a2=(mid<n?(ll)v[mid+1]:(ll)4e18);
            ll b1=(j?(ll)l[j]*t:(ll)-4e18);
            ll b2=(j<n?(ll)l[j+1]*t:(ll)4e18);
            if(a1<=b2&&b1<=a2)
            {
                p=max(a1,b1);
                break;
            }
            if(a1>b2)R=mid-1;
            else L=mid+1;
        }
        int x=ask1(p),y=(t?ask2(p,t):n);
        ll s1=p*x-sv[x]+sv[n]-sv[x]-p*(n-x);
        ll s2=p*y-(ll)t*sl[y]+(ll)t*(sl[n]-sl[y])-p*(n-y);
        ans[i]=(sv[n]-(ll)t*sl[n]+s1+s2)/2;
    }
    for(int i=1;i<=q;i++)
        print(ans[i]),cout<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
